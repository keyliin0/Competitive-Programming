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

int n;
ll t[2 * N];
ll seg[8 * N];

ll get(int p,int s,int e,int l,int r) {
	if (s >= l && e <= r)
		return seg[p];
	if (s > r || e < l)
		return 1e18;
	return min(get(2 * p, s, (s + e) / 2, l, r), get(2 * p + 1, (s + e) / 2 + 1, e, l, r));
}

void build(int p,int s,int e) {
	if (s == e) {
		seg[p] = t[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = min(seg[2 * p], seg[2 * p + 1]);
}

int main() {
	while (1) {
		scanf("%d",&n);
		if (n == 0) return 0;
		loop(i, 0, n - 1)
			scanf("%lld",&t[i]);
		int cnt = n;
		loop(i, 0, n - 1) {
			t[cnt] = t[i];
			cnt++;
		}
		loop(i, 1, cnt - 1)
			t[i] += t[i - 1];
		build(1, 0, cnt - 1);
		int ans = 0;
		ll x = get(1, 0, cnt - 1, 0, n - 1);
		if (x >= 0) ans++;
		loop(i, 1, n - 1) {
			x = get(1, 0, cnt - 1, i, n - 1 + i);
			if (x - t[i - 1] >= 0) ans++;
		}
		printf("%d\n",ans);
	}
}