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


int n;
ll t, a, b;
pair<ll, int> x[N];
int h[N];

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%lld%lld%lld", &n, &t, &a, &b);
		ll hard = 0, easy = 0;
		loop(i, 0, n - 1) {
			scanf("%d", &h[i]);
			hard += h[i] == 1;
			easy += h[i] == 0;
		}
		loop(i, 0, n - 1) {
			x[i].second = i;
			scanf("%lld", &x[i].first);
		}
		sort(x, x + n);
		ll ans = 0;
		if (a * easy + b * hard <= t) ans = n;
		if (x[0].first != 0) {
			ll rem = x[0].first - 1;
			ll x1 = min(easy, rem / a);
			rem -= x1 * a;
			ll x2 = min(hard, rem / b);
			ans = max(ans, x1 + x2);
		}
		ll curr = 0;
		loop(i, 0, n - 2) {
			if (h[x[i].second]) {
				hard--;
				curr += b;
			}
			else {
				easy--;
				curr += a;
			}
			ll total = x[i + 1].first - 1;
			if (curr > total) continue;
			ll rem = total - curr;
			ll x1 = min(easy, rem / a);
			rem -= x1 * a;
			ll x2 = min(hard, rem / b);
			ans = max(ans, 1LL * i + 1 + x1 + x2);
		}
		printf("%lld\n", ans);
	}
}