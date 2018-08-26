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

ll lazy[4 * 100005], seg[4 * 100005];
int n, q, l, r;
ll v;

void process(int p,int s,int e) {
	seg[p] += (ll)(e - s + 1) * lazy[p];
	if (s != e) {
		lazy[2 * p] += lazy[p];
		lazy[2 * p + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p,int s,int e) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] = v;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2);
	update(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

ll get(int p, int s, int e) {
	process(p, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[p];
	return get(2 * p, s, (s + e) / 2) + get(2 * p + 1, (s + e) / 2 + 1, e);
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		memset(lazy, 0, sizeof lazy);
		memset(seg, 0, sizeof seg);
		scanf("%d%d", &n, &q);
		while (q--) {
			int type;
			scanf("%d%d%d", &type, &l, &r);
			l--;
			r--;
			if (type) {
				printf("%lld\n", get(1, 0, n - 1));
			}
			else {
				scanf("%lld", &v);
				update(1, 0, n - 1);
			}
		}
	}
}