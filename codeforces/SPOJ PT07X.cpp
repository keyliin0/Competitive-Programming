/*
	dp on tree
	state : current node and if the last node was included or not
	if the last node was not included then you must include the current node
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
int dp[N][2];

int dfs(int u,int p,int last) {
	if (dp[u][last] != -1) return dp[u][last];
	int choice1 = oo, choice2 = oo;
	if (last) {
		choice1 = 1;
		for (int i = 0; i < g[u].size(); i++)
			if(g[u][i] != p) choice1 += dfs(g[u][i], u, 1);
		choice2 = 0;
		for (int i = 0; i < g[u].size(); i++)
			if(g[u][i] != p) choice2 += dfs(g[u][i], u, 0);
	}
	else {
		choice1 = 1;
		for (int i = 0; i < g[u].size(); i++)
			if (g[u][i] != p) choice1 += dfs(g[u][i], u, 1);
	}
	return  dp[u][last] = min(choice1, choice2);
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(dp, -1, sizeof dp);
	int ans = dfs(1, -1, 1);
	printf("%d",ans);
}