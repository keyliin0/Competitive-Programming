/*
	use bitmask to represent the dishes, try all solutions and memoize
	state : mask of dishes and the previous dish
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

int n, m, k;
ll t[20], g[20][20];
ll dp[1 << 18][20];

// wr 5 , th 15 , rd 1 

ll solve(int mask,int prev) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) cnt++;
	}
	if (cnt >= m) return 0;
	if (dp[mask][prev] != -1) return dp[mask][prev];
	dp[mask][prev] = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) continue;
		dp[mask][prev] = max(dp[mask][prev], g[prev][i] + t[i] + solve(mask | (1 << i), i));
	}
	return dp[mask][prev];
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	loop(i, 0, n - 1)
		scanf("%lld",&t[i]);
	loop(i, 0, k - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		scanf("%lld", &g[a][b]);
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 19);
	printf("%lld",ans);
}