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

int n, k;
ll dp[70][70][105][2];

ll solve(int i,int j,int rem,int last) {
	if (i > n / 2 || j > n / 2) return 0;
	if (i + j == n) {
		return rem == 0 && i == j && last;
	}
	ll &ret = dp[i][j][rem][last];
	if (ret != -1) return ret;
	ret = 0;
	ret += solve(i + 1, j, ((1LL << (i + j)) + rem) % k,1);
	ret += solve(i, j + 1, rem , 0);
	return ret;
}

int main() {
	int t;
	scanf("%d",&t);
	loop(test, 1, t) {
		scanf("%d%d", &n, &k);
		if (k == 0) {
			printf("Case %d: 0\n", test);
			continue;
		}
		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0, 0,0);
		printf("Case %d: %lld\n", test, ans);
	}
}