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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
ll t[N];

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		loop(i, 0, n - 1)
			scanf("%lld", &t[i]);
		ll ans;
		sort(t, t + n);
		ans = t[0] * t[n - 1];
		loop(i, 0, n - 1) {
			if (ans % t[i] != 0) {
				ans = -1;
				break;
			}
		}
		for (ll i = 2; i * i <= ans && ans != -1; i++) {
			if (ans % i == 0) {
				if (!binary_search(t, t + n, i)) {
					ans = -1;
					break;
				}
				if (ans / i != i && !binary_search(t, t + n, ans / i)) {
					ans = -1;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
}