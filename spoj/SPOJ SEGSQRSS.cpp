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

ll seg[N][4], lazy[N], lazy2[N], t[N];
int n,q;
int l, r;
ll v;
int type;

void process(int p, int s, int e) {
	if (lazy2[p] != oo) {
		seg[p][2] = 0;
		seg[p][0] = 1LL * (e - s + 1) * lazy2[p];
		seg[p][1] = seg[p][3] = 1LL * (e - s + 1) * lazy2[p] * lazy2[p];
		lazy2[2 * p] = lazy2[2 * p + 1] = lazy2[p];
		lazy[p] = 0;
		lazy2[p] = oo;
	}
	if (lazy[p] == 0) return;
	seg[p][2] += lazy[p];
	seg[p][1] = seg[p][3] + 1LL * 2 * seg[p][2] * seg[p][0] + 1LL * (e - s + 1) * seg[p][2];
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
		if(type) lazy[p] = v;
		else lazy2[p] = v;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2);
	update(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p][1] = seg[2 * p][1] + seg[2 * p + 1][1];
}

ll get(int p, int s, int e) {
	process(p, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[p][1];
	return get(2 * p, s, (s + e) / 2) + get(2 * p + 1, (s + e) / 2 + 1, e);
}

void build(int p,int s,int e) {
	if (s == e) {
		seg[p][0] = t[s];
		seg[p][1] = seg[p][3] = t[s] * t[s];
		seg[p][2] = 0;
		lazy2[p] = oo;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p][0] = seg[2 * p][0] + seg[2 * p + 1][0];
	seg[p][1] = seg[p][3] = seg[2 * p][1] + seg[2 * p + 1][1];
	lazy2[p] = oo;
}

int main() {
	int test;
	scanf("%d",&test);
	loop(tt,1,test) {
		printf("Case %d:\n",tt);
		scanf("%d%d", &n, &q);
		loop(i, 0, n - 1)
			scanf("%lld", &t[i]);
		memset(lazy, 0, sizeof lazy);
		build(1, 0, n - 1);
		while (q--) {
			scanf("%d%d%d", &type, &l, &r);
			l--;
			r--;
			if (type == 2) {
				printf("%lld\n", get(1, 0, n - 1));
			}
			else{
				scanf("%lld",&v);
				update(1, 0, n - 1);
			}
		}
	}
}