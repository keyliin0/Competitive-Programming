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
int n, m, k;
int d[N];
vector<int> ans, node;

void dfs(int u,int c) {
	if (ans.size()) return;
	if (d[u] == -1) 
		d[u] = c;
	else if (c - d[u] > k) {
		bool take = 0;
		for (int i = 0; i < node.size(); i++) {
			if (node[i] == u) take = 1;
			if (take) ans.push_back(node[i]);
		}
	}
	else return;
	node.push_back(u);
	for (int i = 0; i < g[u].size(); i++)
		dfs(g[u][i], c + 1);
	node.pop_back();
}

int main() {
	scanf("%d%d%d", &n,&m,&k);
	g.resize(n + 1);
	loop(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	dfs(1, 0);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
}