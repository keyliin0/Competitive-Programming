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

int n, m, q;
vector<vector<pair<int, int> > > g;
vector<int> edges;
int dp[55][100005];

int curr;
int cost;
bool dfs(int u,int p,int dest,int cst,int d) {
	if (u == dest) {
		curr = d;
		cost = cst;
		return 1;
	}
	bool f = 0;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].first != p) {
			int res = dfs(g[u][i].first, u, dest, cst + g[u][i].second, d + 1);
			if (res) {
				f = 1;
				if (g[u][i].first != dest) edges.push_back(g[u][i].second);
			}
		}
	}
	return f;
}

int solve(int i,int rem) {
	if (rem == 0) return 0;
	if (rem < 0 || i == edges.size()) return oo;
	int &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, solve(i + 1, rem));
	ret = min(ret, 2 + solve(i, rem - 2 * edges[i]));
	return ret;
}


int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d", &n, &m);
		g.clear();
		g.resize(n + 1);
		loop(i, 0, m - 1) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}
		scanf("%d", &q);
		while (q--) {
			edges.clear();
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			dfs(a, -1, b, 0, 0);
			c -= cost;
			memset(dp, -1, sizeof dp);
			int ans = curr + solve(0, c);
			if (ans >= oo) printf("No\n");
			else printf("Yes %d\n", ans);
		}
		if (test) printf("\n");
	}
}