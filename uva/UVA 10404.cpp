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

int dp[1000005];
int n, m;
int t[15];

int solve(int n) {
	if (n == 0) return 1; // the previous player win
	if (dp[n] != -1) return dp[n];
	loop(i, 0, m - 1) {
		if (n < t[i]) continue;
		int res = solve(n - t[i]);
		if (res) return dp[n] = 0; // i can win so the previous player lose
	}
	return dp[n] = 1; // i cant win so the previous player win
}

int main() {
	while (scanf("%d", &n) != EOF) {
		scanf("%d",&m);
		loop(i, 0, m - 1)
			scanf("%d",&t[i]);
		memset(dp, -1, sizeof dp);
		if (!solve(n)) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
}