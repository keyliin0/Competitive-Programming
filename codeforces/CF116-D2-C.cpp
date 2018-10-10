/*
	if we trace some test cases we can see that the answer will be the max depth in the tree
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
vector <vector<int> >  g;
bool vis[2005], root[2005];
int ans;

void dfs(int u,int c) {
	ans = max(ans, c);
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		if (!vis[g[u][i]])
			dfs(g[u][i], c + 1);
	}
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	memset(root, 1, sizeof root);
	loop(i, 1, n) {
		int a;
		scanf("%d",&a);
		if (a == -1) continue;
		g[a].push_back(i);
		root[i] = 0;
	}
	loop(i, 1, n)
		if (root[i]) dfs(i, 1);
	printf("%d",ans);
}