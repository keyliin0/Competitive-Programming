/*
	use dp on graph 
	dp[i][j] = min time to reach node i while visiting j nodes
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
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

int n, m, t;
int dp[5001][5001],path[5001][5001];
vector<vector<pair<int, int> > > g;

void dfs(int u, int j) {
	for (int i = 0; i < g[u].size(); i++) {
		if (dp[u][j] + g[u][i].second <= t && dp[u][j] + g[u][i].second < dp[g[u][i].first][j + 1]) {
			path[g[u][i].first][j + 1] = u;
			dp[g[u][i].first][j + 1] = dp[u][j] + g[u][i].second;
			dfs(g[u][i].first, j + 1);
		}
	}
}

void build(int u, int j) {
	if (u == 1) return;
	build(path[u][j], j - 1);
	printf("%d ", path[u][j]);
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	g.resize(n + 1);
	loop(i, 1, n)
		loop(j, 0, n)
		dp[i][j] = i == 1 ? 0 : 1e9 + 5;
	loop(i, 0, m - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back({ b,c });
	}
	dfs(1, 0);
	int k;
	loop2(i, n, 1) {
		if (dp[n][i] <= t) {
			k = i;
			break;
		}
	}
	printf("%d\n", k + 1);
	build(n, k);
	printf("%d", n);
}