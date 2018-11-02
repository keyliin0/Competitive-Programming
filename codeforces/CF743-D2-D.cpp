/*
	calculate the max sum for each subtree
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
vector<vector<int> > g;
ll t[N];
pair<ll, ll> dp[200005];
ll ans = -1e18;

void dfs(int u, int p) {
	dp[u].second = t[u];
	dp[u].first = -1e18;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] == p) continue;
		dfs(g[u][i], u);
		dp[u].first = max({ dp[u].first , dp[g[u][i]].first });
		dp[u].second += dp[g[u][i]].second;
	}
	dp[u].first = max({ dp[u].first, dp[u].second });
}

void dfs2(int u, int p) {
	vector<ll> v;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] == p) continue;
		dfs2(g[u][i], u);
		v.push_back(dp[g[u][i]].first);
	}
	sort(v.begin(), v.end());
	if (v.size() >= 2) ans = max(ans, v[v.size() - 1] + v[v.size() - 2]);
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	loop(i, 1, n)
		scanf("%lld", &t[i]);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, -1);
	dfs2(1, -1);
	if (ans == -1e18) printf("Impossible");
	else printf("%lld\n", ans);
}