/*	
	calculate the max cost that you can reach starting from the cells (n,1) & (1,1) to all other cells using dp
	now for each cell (i,j) we have the max cost , now we only need the cost that to (n,m) and (1,m)
	do the same first step but starting from (n,m) and (1,m)
	now with a simple loop find the answer
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

ll a[1005][1005], dp[1005][1005][4];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 1, n) {
		loop(j, 1,m) {
			scanf("%lld", &a[i][j]);
		}
	}
	loop(i, 1, n) { //topleft ///////
		loop(j, 1, m) {
			dp[i][j][0] = a[i][j] + max(dp[i - 1][j][0], dp[i][j - 1][0]);
		}
	}
	loop2(i, n, 1) { // downleft *************
		loop(j, 1, m) {
			dp[i][j][1] = a[i][j] + max(dp[i + 1][j][1], dp[i][j - 1][1]);
		}
	}
	loop2(i, n, 1) { // downright /////////
		loop2(j, m, 1) {
			dp[i][j][2] = a[i][j] + max(dp[i + 1][j][2], dp[i][j + 1][2]);
		}
	}
	loop(i, 1, n) { // topright
		loop2(j, m, 1) {
			dp[i][j][3] = a[i][j] + max(dp[i - 1][j][3], dp[i][j + 1][3]);
		}
	}
	ll ans = 0;
	loop(i, 2, n - 1) {
		loop(j, 2, m - 1) {
			ans = max(ans, dp[i][j - 1][0] + dp[i][j + 1][2] + dp[i - 1][j][3] + dp[i + 1][j][1]);
			ans = max(ans, dp[i - 1][j][0] + dp[i + 1][j][2] + dp[i][j + 1][3] + dp[i][j - 1][1]);
		}
	}
	printf("%lld", ans);
}