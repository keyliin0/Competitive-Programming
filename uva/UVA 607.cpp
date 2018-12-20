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

ll dp[1005][1005];
int n, k, l, c;
int t[N];

ll solve(int i,int j) {
	if (i == n + 1) {
		if (k != j) return 1e15;
		return 0;
	}
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = 1e15;
	for (int u = i; u <= n; u++) {
		if (t[u] - t[i - 1] > l) break;
		ll x;
		if (l - (t[u] - t[i - 1]) == 0) x = 0;
		else if (l - (t[u] - t[i - 1]) >= 1 && l - (t[u] - t[i - 1]) <= 10) x = -c;
		else x = (l - (t[u] - t[i - 1]) - 10) * (l - (t[u] - t[i - 1]) - 10);
		ret = min(ret, x + solve(u + 1, j + 1));
	}
	return ret;
}

int main() {
	int cas = 0;
	while (1) {
		scanf("%d",&n);
		if (n == 0) return 0;
		if (cas != 0) printf("\n");
		scanf("%d%d", &l, &c);
		int curr = 0;
		k = 1;
		loop(i, 1, n) {
			scanf("%d", &t[i]);
			curr += t[i];
			if (curr > l) curr = t[i], k++;
			t[i] += t[i - 1];
		}
		memset(dp, -1, sizeof dp);
		ll ans = solve(1, 0);
		printf("Case %d:\n",++cas);
		printf("Minimum number of lectures: %d\n", k);
		printf("Total dissatisfaction index: %lld\n", ans);
	}
}