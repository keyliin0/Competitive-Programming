/*
	n = a^2 - b^2 = (a - b) * (a + b)
	if we sum (a - b) and (a + b) we get 2 * a 
	so if a solution exist the sum of (a - b) and (a + b) must be even 
	Bachelor Numbers are the numbers where (a - b) + (a + b) is odd so (a - b) or (a + b) is even and the other is odd
	this can happen only if we divide n / 2 we get a prime number 
	now observe the first Bachelor Numbers starts from 2 and increase by 4 : 2 6 10 ..
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


ll get(ll n) {
	n = abs(n);
	if (n < 2)  return 0;
	return (n - 2) / 4 + 1;
}

int main() {
	char cmd[50];
	ll n1, n2;
	while (gets(cmd)) {
		if (sscanf(cmd, "%lld %lld", &n1, &n2) == 2) {
			ll r = get(n2);
			ll l = get(abs(n1) - 1);
			ll ans;
			if (n1 < 0 && n2 > 0) ans = r + l;
			else ans = r - l;
			printf("%lld\n",ans);
		}
		else {
			sscanf(cmd, "%lld", &n1);
			if (n1 == 0) {
				printf("2 2\n");
				continue;
			}
			bool yes = 0;
			for (ll i = 1; i * i <= n1; i++) {
				if (n1 % i != 0) continue;
				ll x = n1 / i;
				ll a = x + i;
				if (a % 2 != 0) continue;
				a /= 2;
				yes = 1;
				ll mx = max(x, i);
				ll b = mx - a;
				yes = 1;
				if (a < b) swap(a, b);
				printf("%lld %lld\n", a, b);
				break;
			}
			if (!yes) {
				if (n1 % 2 == 0) printf("Bachelor Number.\n");
				else printf("Spinster Number.\n");
			}
		}
	}
}