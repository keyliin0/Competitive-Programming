/*
	https://en.wikipedia.org/wiki/Josephus_problem
	here we searching for josephus(Y,2) = X
	josephus(i,2): 1 1 3 1 3 5 7 1 3 5 7 9 11 13 15
	there is a nice pattern here
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
#define logg2  0.30102999566398119521373889472449L
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

ll x, l, n;

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main() {
	int test;
	scanf("%d", &test);
	loop(tt, 1, test) {
		scanf("%lld%lld%lld", &x, &l, &n);
		ll total = n - l + 1;
		ll p = 0;
		p += max(0LL, x - l);
		if (x % 2 != 0) {
			ll k = 1;
			ll d = (x + 1) / 2;
			ll pos = 1;
			while (k < d) {
				pos += k;
				k *= 2;
			}
			while (pos + d - 1 <= n) {
				if (pos + d - 1 >= l) p++;
				pos += k;
				k *= 2;
			}
		}
		if (p != 0) {
			ll g = GCD(p, total);
			total /= g;
			p /= g;
		}
		printf("Case %d: %lld/%lld\n", tt, p, (p == 0 ? 1 : total));
	}
}