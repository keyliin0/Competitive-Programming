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

int n;
vector<vector<int> > g;
int x, mx = -1,ans;

void dfs1(int u, int d,int p) {
	if (d > mx) x = u,mx = d;
	for (int i = 0; i < g[u].size(); i++)
		if(g[u][i] != p) 
			dfs1(g[u][i], d + 1, u);
}

void dfs2(int u, int d, int p) {
	ans = max(ans, d);
	for (int i = 0; i < g[u].size(); i++)
		if (g[u][i] != p)
			dfs2(g[u][i], d + 1, u);
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1, 0, -1);
	dfs2(x, 0,-1);
	printf("%d",ans);
}