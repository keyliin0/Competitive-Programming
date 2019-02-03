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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

double dp[105][105][105];
int r, s, p;
double ans[3];

int main() {
	scanf("%d%d%d", &r, &s, &p);
	dp[r][s][p] = 1.0;
	for (int rr = r; rr >= 0; rr--)
		for (int ss = s; ss >= 0; ss--)
			for (int pp = p; pp >= 0; pp--) {
				double all = rr * ss + rr * pp + ss * pp;
				if (rr && ss) dp[rr][ss - 1][pp] += dp[rr][ss][pp] * ((rr * ss) / all);
				if (ss && pp) dp[rr][ss][pp - 1] += dp[rr][ss][pp] * ((ss * pp) / all);
				if (pp && rr) dp[rr - 1][ss][pp] += dp[rr][ss][pp] * ((pp * rr) / all);
			}
	for (int i = 0; i <= r; i++)
		ans[0] += dp[i][0][0];
	for (int i = 0; i <= s; i++)
		ans[1] += dp[0][i][0];
	for (int i = 0; i <= p; i++)
		ans[2] += dp[0][0][i];
	printf("%.9lf %.9lf %.9lf", ans[0], ans[1], ans[2]);
}