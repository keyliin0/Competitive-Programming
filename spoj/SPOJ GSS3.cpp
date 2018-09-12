/*
	https://github.com/keyliin0/Competitive-Programming/blob/master/spoj/SPOJ%20GSS1.cpp
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

int n, q;
int t[N];

struct node {
	int suffix, sub, prefix, sum;
};

node seg[4 * 50005];
int idx, x;

node get(int p, int s, int e, int l, int r) {
	if (s > r || e < l) {
		node ret;
		ret.suffix = ret.sub = ret.prefix = -oo;
		ret.sum = 0;
		return ret;
	}
	if (s >= l && e <= r) return seg[p];
	node a = get(2 * p, s, (s + e) / 2, l, r);
	node b = get(2 * p + 1, (s + e) / 2 + 1, e, l, r);
	node ret;
	ret.sum = a.sum + b.sum;
	ret.prefix = max(a.prefix, a.sum + b.prefix);
	ret.suffix = max(b.suffix, b.sum + a.suffix);
	ret.sub = max(max(a.sub, b.sub), a.suffix + b.prefix);
	return ret;
}

void update(int p, int s, int e) {
	if (s == e) {
		seg[p].suffix = seg[p].sub = seg[p].prefix = seg[p].sum = x;
		return;
	}
	if(idx <= (s + e) / 2) update(2 * p, s, (s + e) / 2);
	else update(2 * p + 1, (s + e) / 2 + 1, e);
	// merge
	seg[p].sum = seg[2 * p].sum + seg[2 * p + 1].sum;
	seg[p].prefix = max(seg[2 * p].prefix, seg[2 * p].sum + seg[2 * p + 1].prefix);
	seg[p].suffix = max(seg[2 * p + 1].suffix, seg[2 * p + 1].sum + seg[2 * p].suffix);
	seg[p].sub = max(max(seg[2 * p].sub, seg[2 * p + 1].sub), seg[2 * p].suffix + seg[2 * p + 1].prefix);
}


void build(int p, int s, int e) {
	if (s == e) {
		seg[p].suffix = seg[p].sub = seg[p].prefix = seg[p].sum = t[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	// merge
	seg[p].sum = seg[2 * p].sum + seg[2 * p + 1].sum;
	seg[p].prefix = max(seg[2 * p].prefix, seg[2 * p].sum + seg[2 * p + 1].prefix);
	seg[p].suffix = max(seg[2 * p + 1].suffix, seg[2 * p + 1].sum + seg[2 * p].suffix);
	seg[p].sub = max(max(seg[2 * p].sub, seg[2 * p + 1].sub), seg[2 * p].suffix + seg[2 * p + 1].prefix);
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1)
		scanf("%d", &t[i]);
	build(1, 0, n - 1);
	scanf("%d", &q);
	while (q--) {
		int type;
		scanf("%d",&type);
		if (type == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			r--;
			node g = get(1, 0, n - 1, l, r);
			int ans = max(max(g.prefix, g.sub), max(g.suffix, g.sum));
			printf("%d\n", ans);
		}
		else {
			scanf("%d%d", &idx, &x);
			idx--;
			update(1, 0, n - 1);
		}
	}
}