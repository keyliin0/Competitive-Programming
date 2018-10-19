/*
	for each mask check if the chosen nodes can cover all the nodes 
	now each time choose some nodes ( masks ) that can cover all the nodes and memoize the max
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

vector<vector<int> > g;
int n;
bool vis[20];
vector<int> v;
int dp[1 << 16];
bool ok[1 << 16];

int solve(int mask) {
	if (mask == 0) return 0;
	int &ret = dp[mask];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = mask; i > 0; i = (i - 1) & mask) { // iterate only through the needed masks
		if (ok[i]) ret = max(ret, 1 + solve(mask ^ i));
	}
	return ret;
}

int main() {
	int cas = 0;
	while (1) {
		scanf("%d",&n);
		if (n == 0) return 0;
		g.clear();
		g.resize(n + 1);
		loop(i, 0, n - 1) {
			int a;
			scanf("%d",&a);
			for(int j = 0;j < a;j++) {
				int b;
				scanf("%d",&b);
				g[i].push_back(b);
			}
		}
		memset(ok, 0, sizeof ok);
		for (int mask = 0; mask < (1 << n); mask++) {
			memset(vis, 0, sizeof vis);
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					cnt += !vis[i];
					vis[i] = 1;
					for (int u = 0; u < g[i].size(); u++) {
						cnt += !vis[g[i][u]];
						vis[g[i][u]] = 1;
					}
				}
			}
			if (cnt == n) ok[mask] = 1;
		}
		memset(dp, -1, sizeof dp);
		int ans = solve((1 << n) - 1);
		printf("Case %d: %d\n",++cas,ans);
	}
}