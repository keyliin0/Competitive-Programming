/*
	an optimal sol is to make the consecutive >= k answer from the start
	to get the optimal ans the consecutive right answers at the beginning must be the least possible
	binary search for this number
	the score of consecutive answers = (2^(len + 1) - 2) * k 
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
const ll mod = 1e9 + 9;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll n, m, k;

ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) % mod * a) % mod;
	return (res*res) % mod;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	ll l = 0, r = m,mn = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll block = m - mid;
		if (n - m >= (block + k - 2)  / (k-1)  ) {
			mn = min(mn, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (n == m) mn = m;
	ll ans = (((((fastPower(2, mn / k + 1) - 2 + mod) % mod) * k) % mod) + m - mn + (mn % k)) % mod;
	printf("%lld",ans);
}