/*
	make free cells equal to 1 and other cells to -INFINITY
	now the problem is to find the largest sum in a subrectangle
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

int n, b;
int dp[105];
int g[105][105];

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		loop(i, 1, n)
			loop(j, 1, n)
				g[i][j] = 1;
		scanf("%d",&b);
		while (b--) {
			int a, b, c, d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			loop(i, a, c) {
				loop(j, b, d) {
					g[i][j] = -1e6;
				}
			}
		}
		loop(j, 1, n)
			loop(i, 1, n)
				g[i][j] += g[i - 1][j];
		int ans = 0;
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) {
				dp[1] = g[i + len - 1][1] - g[i - 1][1];
				ans = max(ans, dp[1]);
				for (int j = 2; j <= n; j++) {
					dp[j] = max(dp[j - 1] + g[i + len - 1][j] - g[i - 1][j], g[i + len - 1][j] - g[i - 1][j]);
					ans = max(ans, dp[j]);
				}
			}
		}
		printf("%d\n",ans);
	}
}