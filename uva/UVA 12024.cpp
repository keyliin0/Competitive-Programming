/*
	the first one can take n - 1 hats , the next one n - 2 and so one
	find the number of ways with memo
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

int n;
int dp[14][8192];

int solve(int p,int mask) {
	if (p == 0) return 1;
	int &ret = dp[p][mask];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (i != p && !(mask & (1 << i)))
			ret += solve(p - 1, mask | (1 << i));
	}
	return ret;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		int ans = solve(n, 0);
		int q = 1;
		loop(i, 1, n) {
			q *= i;
		}
		printf("%d/%d\n", ans, q);
	}
}