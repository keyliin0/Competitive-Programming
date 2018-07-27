/*
	binary search for N
	try every value of K and count the number of ways : if we divide N by k^3 we get the min number that we can start with using the current value of K
	that means we can start with less values starting from 1
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

ll m;

int main() {
	scanf("%lld",&m);
	ll l = 1, r = 1e18,ans = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll ways = 0;
		for (ll k = 2; k <= 1e6; k++) {
			ll tmp = mid;
			tmp = tmp / (k * k * k);
			if (tmp == 0) break;
			ways += tmp;
		}
		if (ways >= m) {
			if (ways == m) ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld",ans);
}