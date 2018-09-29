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

int n, t;
double p, dp[55][55];
bool vis[55][55];

double solve(int i,int won) {
	if (won == n) return 1;
	if (i == 2 * n - 1) return 0;
	double &ret = dp[i][won];
	if (vis[i][won]) return ret;
	vis[i][won] = 1;
	ret += p * solve(i + 1, won + 1);
	ret += (1.0 - p) * solve(i + 1, won);
	return ret;
}

int main() {
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d%lf", &n, &p);
		for (int i = 0; i <= 52; i++) {
			for (int j = 0; j <= 52; j++) {
				dp[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		double ans = solve(0, 0);
		printf("%.2lf\n", ans);
	}
}