/*
	use seg tree
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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

pair<int,int> seg[N];
int lazy[N];
int n;
// 45
int mx = 100000;

void process(int p, int s, int e) {
	if (lazy[p] == 0) return;
	seg[p].first = lazy[p];
	seg[p].second = lazy[p];
	lazy[2 * p] = lazy[p];
	lazy[2 * p + 1] = lazy[p];
	lazy[p] = 0;
}

int get(int p, int s, int e, int l, int r, int h) {
	process(p, s, e);
	if (seg[p].second > h) return 0; // if min in this range > h
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) {
		if (seg[p].first <= h) { // if max in current range <= h then we can take this range and update it
			lazy[p] = h;
			process(p, s, e);
			return e - s + 1;
		}
	}
	int res = get(2 * p, s, (s + e) / 2, l, r, h) + get(2 * p + 1, (s + e) / 2 + 1, e, l, r ,h);
	seg[p].first = max(seg[2 * p].first, seg[2 * p + 1].first);
	seg[p].second = min(seg[2 * p].second, seg[2 * p + 1].second);
	return res;
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		memset(lazy, 0, sizeof lazy);
		loop(i, 0, 500000) {
			seg[i].first = seg[i].second = 0;
		}
		int ans = 0;
		loop(i, 0, n - 1) {
			int l, r, h;
			scanf("%d%d%d", &l, &r, &h);
			ans += get(1, 0, mx - 1, l - 1, r - 2, h);
		}
		printf("%d\n", ans);
	}
}