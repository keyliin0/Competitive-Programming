/*
	try to remove each edge now we have two connected components, we can find the diameter for each component and multiply them
	obviously the max will be the answer
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
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

vector<vector<int> > g;
int n;
bool vis[205];

int mx, node;
void dfs(int u,int d) {
	if (d > mx) {
		mx = d;
		node = u;
	}
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		if (!vis[g[u][i]]) dfs(g[u][i], d + 1);
	}
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int a = i;
			int b = g[i][j];
			memset(vis, 0, sizeof vis);
			vis[b] = 1;
			mx = -1;
			dfs(a, 0);
			memset(vis, 0, sizeof vis);
			vis[b] = 1;
			mx = -1;
			dfs(node, 0);
			int curr = mx;
			memset(vis, 0, sizeof vis);
			vis[a] = 1;
			mx = -1;
			dfs(b, 0);
			memset(vis, 0, sizeof vis);
			vis[a] = 1;
			mx = -1;
			dfs(node, 0);
			curr *= mx;
			ans = max(ans, curr);
		}
	}
	printf("%d",ans);
}