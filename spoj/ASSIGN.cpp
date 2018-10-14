/*
	try to assign all the non assigned topic to each student and memoize the number of ways
	mask is the assignments that are already assigned
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
int t[20][20];
ll dp[20][1 << 20];
 
ll solve(int i,int mask) {
	if (i == n) return 1;
	ll &ret = dp[i][mask];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = 0; j < n; j++) {
		if (t[i][j] && !(mask & (1 << j)))
			ret += solve(i + 1, mask | (1 << j));
	}
	return ret;
}
 
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d", &n);
		loop(i, 0, n - 1)
			loop(j, 0, n - 1)
			scanf("%d", &t[i][j]);
		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0);
		printf("%lld\n", ans);
	}
} 