/*
	use segment tree to find which envelope will be picked
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

int n, m, k;
const int MAX = 4 * 1e5 + 2;
pair<int, int> seg[MAX], lazy[MAX];
ll dp[100005][205];
pair<int, int> W[100005];

bool cmp(pair<int,int> i,pair<int,int> j) {
	if (i.first == j.first) return i.second > j.second;
	return i.first > j.first;
}

void process(int p, int s, int e) {
	if (lazy[p].first == 0) return;
	if (cmp(lazy[p], seg[p])) seg[p] = lazy[p];
	if (s != e) {
		if (cmp(lazy[p], lazy[2 * p])) lazy[2 * p] = lazy[p];
		if (cmp(lazy[p], lazy[2 * p + 1])) lazy[2 * p + 1] = lazy[p];
	}
	lazy[p] = { 0,0 };
}

void update(int p,int s,int e,int l,int r,int w,int d) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] = { w,d };
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2, l, r, w, d);
	update(2 * p + 1, (s + e) / 2 + 1, e, l, r, w, d);
	if (cmp(seg[2 * p], seg[2 * p + 1])) seg[p] = seg[2 * p];
	else seg[p] = seg[2 * p + 1];
}

pair<int,int> get(int p, int s, int e, int i) {
	process(p, s, e);
	if (s == e) return seg[p];
	if (i <= (s + e) / 2) return get(2 * p, s, (s + e) / 2, i);
	else return get(2 * p + 1, (s + e) / 2 + 1, e, i);
}

ll calc(int i, int rem) {
	if (i > n) return 0;
	ll &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = 1e18;
	if (rem) ret = min(ret, calc(i + 1, rem - 1));
	if (W[i].first == 0) ret = min(ret, calc(i + 1, rem));
	else ret = min(ret, W[i].first + calc(W[i].second + 1, rem));
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	loop(i, 0, k - 1) {
		int s, t, d, w;
		scanf("%d%d%d%d", &s, &t, &d, &w);
		update(1, 1, n, s, t, w, d);
	}
	loop(i, 1, n) {
		W[i] = get(1, 1, n, i);
	}
	memset(dp, -1, sizeof dp);
	ll ans = calc(1, m);
	printf("%lld", ans);
}