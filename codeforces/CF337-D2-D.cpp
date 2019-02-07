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

int n, m, d;
bool v[N];
vector<vector<int> > g;
int in[N], out[N];

void dfs1(int u,int p) {
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] != p) {
			dfs1(g[u][i], u);
			in[u] = max(in[u], 1 + in[g[u][i]]);
		}
	}
}

void dfs2(int u,int p) {
	if (v[u]) out[u] = max(0, out[u]);
	int mx1 = -oo, mx2 = -oo;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] != p) {
			if (in[g[u][i]] >= mx1) mx2 = mx1, mx1 = in[g[u][i]];
			else if (in[g[u][i]] > mx2) mx2 = in[g[u][i]];
		}
	}
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] != p) {
			int use = mx1;
			if (mx1 == in[g[u][i]])
				use = mx2;
			out[g[u][i]] = max(1 + out[u], 2 + use);
			dfs2(g[u][i], u);
			if (v[g[u][i]]) out[g[u][i]] = max(out[g[u][i]], 0);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &d);
	g.resize(n + 1);
	loop(i, 0, m - 1) {
		int a;
		scanf("%d", &a);
		v[a] = 1;
	}
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	loop(i, 1, n)
		if(!v[i]) in[i] = -oo,out[i] = -oo;
	dfs1(1, -1);
	dfs2(1, -1);
	int ans = 0;
	loop(i, 1, n)
		if (max(in[i], out[i]) <= d) ans++;
	printf("%d",ans);
}