/*
	if we visit a value Ai that and then we visit a value > Ai we add a new builing
	if we already visited a value Ai then we dont add it to the answer 
	use segment tree to mark the range Ai + 1 to max not visited
	since the values can be large we can use compress them cause we only need 10^5
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, t[N];
bool seg[4 * 100005];
int lazy[4 * 100005];

void process(int p,int s,int e) {
	if (lazy[p] == -1) return;
	seg[p] = lazy[p];
	if (s != e) {
		lazy[2 * p] = lazy[p];
		lazy[2 * p + 1] = lazy[p];
	}
	lazy[p] = -1;
}

void update(int p, int s, int e,int l,int r,int v) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] = v;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2, l, r, v);
	update(2 * p + 1, (s + e) / 2 + 1, e, l, r, v);
}

bool get(int p,int s,int e,int i) {
	process(p, s, e);
	if (s == e) {
		return seg[p];
	}
	if (i <= (s + e) / 2) return get(2 * p, s, (s + e) / 2, i);
	else return get(2 * p + 1, (s + e) / 2 + 1, e, i);
}

int main() {
	int test = 0;
	while (scanf("%d", &n) != EOF) {
		memset(lazy, -1, sizeof lazy);
		memset(seg, 0, sizeof seg);
		test++;
		map<int, int> mp;
		vector<int> v;
		loop(i, 0, n - 1) {
			scanf("%d", &t[i]);
			v.push_back(t[i]);
		}
		sort(v.begin(), v.end());
		mp[0] = 0;
		if(v[0] != 0) mp[v[0]] = 1;
		int cnt = 2;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] != v[i - 1]) mp[v[i]] = cnt++;
		}
		loop(i, 0, n - 1) {
			t[i] = mp[t[i]];
		}
		int ans = 0, mx = mp[v[v.size() - 1]];
		loop(i, 0, n - 1) {
			if (t[i] != mx) update(1, 0, mx, t[i] + 1, mx, 0);
			if (t[i] != 0 && !get(1, 0, mx, t[i])) {
				update(1, 0, mx, t[i], t[i], 1);
				ans++;
			}
		}
		printf("Case %d: %d\n", test, ans);
	}
}