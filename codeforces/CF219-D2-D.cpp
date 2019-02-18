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

int n;
vector<vector<pair<int, int> > > g;

int in[N], out[N];

void dfs1(int u, int p) {
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].first != p) {
			dfs1(g[u][i].first, u);
			in[u] += in[g[u][i].first] + g[u][i].second;
		}
	}
}

void dfs2(int u, int p) {
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].first != p) {
			out[g[u][i].first] += out[u] + in[u] - in[g[u][i].first] + (g[u][i].second ? -1 : 1);
			dfs2(g[u][i].first, u);
		}
	}
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back({ b,0 });
		g[b].push_back({ a,1 });
	}
	dfs1(1, -1);
	dfs2(1, -1);
	int ans = oo;
	loop(i, 1, n)
		ans = min(ans, in[i] + out[i]);
	printf("%d\n",ans);
	loop(i, 1, n)
		if (in[i] + out[i] == ans)
			printf("%d ",i);
}