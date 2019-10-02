#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int m;
ll n;
ll t[N];
ll seg[N], lazy[N];
ll l, r, v;

void process(int p, int s, int e) {
	seg[p] += (ll)(e - s + 1) * lazy[p];
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
		lazy[p] += v;
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
	scanf("%lld%d", &n, &m);
	loop(i, 1, m)
		scanf("%lld",&t[i]);
	ll ans = 0;
	loop(i, 2, m) {
		ll a = t[i];
		ll b = t[i - 1];
		if (a == b) continue;
		if (a > b) swap(a, b);
		if (b - a >= 2) {
			v = (b - a - 1);
			l = a + 1, r = b - 1;
			update(1, 0, n + 1);
		}
		v = (b - a);
		if (a - 1 >= 1) {
			l = 1, r = a - 1;
			update(1, 0, n + 1);
		}
		if (b + 1 <= n) {
			l = b + 1, r = n;
			update(1, 0, n + 1);
		}
		v = b - 1;
		l = a, r = a;
		update(1, 0, n + 1);
		v = a;
		l = b, r = b;
		update(1, 0, n + 1);
		ans += b + a;
	}
	loop(i, 1, n) {
		l = r = i;
		printf("%lld ", get(1, 0, n + 1));
	}
}