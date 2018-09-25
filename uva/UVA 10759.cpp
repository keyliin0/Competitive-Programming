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

int n, x;
ll dp[30][200];

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

ll solve(int i,int curr) {
	if (i == n) return curr >= x;
	ll &ret = dp[i][curr];
	if (ret != -1) return ret;
	ret = 0;
	loop(j, 1, 6)
		ret += solve(i + 1, curr + j);
	return ret;
}

int main() {
	while (scanf("%d%d", &n, &x)) {
		if (n == 0 && x == 0) return 0;
		ll total = pow(6, n);
		memset(dp, -1, sizeof dp);
		ll p = solve(0, 0);
		ll g = GCD(total, p);
		p /= g;
		total /= g;
		if (total == 1 || p == 0) printf("%lld\n", p);
		else printf("%lld/%lld\n", p, total);
	}
}