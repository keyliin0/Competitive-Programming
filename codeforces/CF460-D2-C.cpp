/*
	update the range from l to r m times 
	l = index of min value (left most if the same min exist multiple times) 
	r = l + w - 1 or n - 1
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

pair<ll, int> seg[4 * 100005];
ll lazy[4 * 100005];
ll t[N];
int n;
ll w, m;

void process(int p,int s,int e) {
	seg[p].first += lazy[p];
	if (s != e) {
		lazy[2 * p] += lazy[p];
		lazy[2 * p + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p,int s,int e,int l,int r) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p]++;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2, l, r);
	update(2 * p + 1, (s + e) / 2 + 1, e, l, r);
	seg[p].first = min(seg[2 * p].first, seg[2 * p + 1].first);
	if (seg[2 * p].first <= seg[2 * p + 1].first)
		seg[p].second = seg[2 * p].second;
	else seg[p].second = seg[2 * p + 1].second;
}

void build(int p,int s,int e) {
	if (s == e) {
		seg[p].first = t[e];
		seg[p].second = e;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p].first = min(seg[2 * p].first, seg[2 * p + 1].first);
	if (seg[2 * p].first <= seg[2 * p + 1].first)
		seg[p].second = seg[2 * p].second;
	else seg[p].second = seg[2 * p + 1].second;
}


int main() {
	scanf("%d%lld%lld", &n, &m, &w);
	loop(i, 0, n - 1) {
		scanf("%lld", &t[i]);
	}
	build(1, 0, n - 1);
	while (m--) {
		update(1, 0, n - 1, seg[1].second, min(seg[1].second + w - 1,(ll) n - 1));
	}
	process(1, 0, n - 1);
	printf("%lld",seg[1].first);
}