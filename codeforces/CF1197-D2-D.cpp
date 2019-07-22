/*
	use DP
	state is : current index - number of elements added % m 
	the base case is a subarray of size 1 
	so all indices with number of elements equal 0 start with a[i] - k
	
*/
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
 
ll t[N];
int n, m;
ll k;
 
ll dp[300005][11];
 
int main() {
	scanf("%d%d%lld", &n, &m, &k);
	loop(i, 0, n - 1)
		scanf("%lld",&t[i]);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		dp[i][0] = t[i] - k;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = -1e18;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j != m - 1) dp[i + 1][(j + 1) % m] = max(dp[i + 1][(j + 1) % m], dp[i][j] + t[i + 1]);
			else dp[i + 1][(j + 1) % m] = max(dp[i + 1][(j + 1) % m], dp[i][j] + t[i + 1] - k);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++)
			ans = max(ans, dp[i][j]);
	}
	cout << ans;
}