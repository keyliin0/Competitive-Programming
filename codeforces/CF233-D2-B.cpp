#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

ll n;

bool check(ll x,int i) {
	int sum = 0;
	while (x != 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum == i;
}

int main() {
	scanf("%lld",&n);
	ll ans = 1e18;
	for (int i = 1; i <= 90; i++) {
		int root = sqrt(i * i + 4 * n);
		ll res1 = (-i - root) / 2;
		ll res2 = (-i + root) / 2;
		if (check(res1,i) && res1 * res1 + res1 * i - n == 0) ans = min(ans, res1);
		if (check(res2,i) && res2 * res2 + res2 * i - n == 0) ans = min(ans, res2);
	}
	printf("%lld", (ans == 1e18 ? -1 : ans));
}