/*
	compress cords 
	use segment tree to get the number of ppl he will meet in a range 
	if someone comes at moment L then add 1 to the range from L to the end of the array 
	use binary search to find the optimal range 
*/

#include <bits/stdc++.h>
#include <unordered_map>
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
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


const int MAX = 200005;
int n, p;
int seg[4 * MAX], lazy[4 * MAX];
int l, r, vv;
int mp[MAX];

void process(int p, int s, int e) {
	if (lazy[p] == 0) return;
	seg[p] += lazy[p];
	if (s != e) {
		lazy[2 * p] += lazy[p];
		lazy[2 * p + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int s, int e) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] += vv;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2);
	update(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = max(seg[2 * p], seg[2 * p + 1]);
}

int get(int p, int s, int e) {
	process(p, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[p];
	return max(get(2 * p, s, (s + e) / 2), get(2 * p + 1, (s + e) / 2 + 1, e));
}


int main() {
	int test;
	scanf("%d", &test);
	loop(tt, 1, test) {
		memset(lazy, 0, sizeof lazy);
		memset(seg, 0, sizeof seg);
		scanf("%d%d", &n, &p);
		vector<pair<int, int> > q;
		vector<int> v;
		unordered_map<int, int> cmp;
		loop(i, 0, n - 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			q.push_back({ l,r });
			v.push_back(l);
			v.push_back(r);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		cmp[v[0]] = cnt;
		mp[cnt] = v[0];
		cnt++;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] != v[i - 1]) {
				cmp[v[i]] = cnt;
				mp[cnt] = v[i];
				cnt++;
			}
		}
		vector<vector<int> > Q;
		Q.resize(cnt + 1);
		vv = 1;
		for (int i = 0; i < q.size(); i++) {
			l = cmp[q[i].first];
			r = cmp[q[i].second];
			Q[r].push_back(l);
			r = cnt - 1;
			update(1, 0, cnt - 1);
		}
		vv = -1;
		int ans = oo;
		for (int i = 0; i < cnt; i++) {
			int L = i, R = cnt - 1;
			l = i;
			while (L <= R) {
				int mid = (L + R) / 2;
				r = mid;
				int g = get(1, 0, cnt - 1);
				if (g >= p) {
					ans = min(ans, mp[r] - mp[l]);
					R = mid - 1;
				}
				else L = mid + 1;
			}
			r = cnt - 1;
			for (int j = 0; j < Q[i].size(); j++) {
				l = Q[i][j];
				update(1, 0, cnt - 1);
			}
		}
		printf("Case %d: %d\n", tt, ans);
	}
}