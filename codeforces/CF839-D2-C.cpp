/*
	the probability of visiting a node is prop of visiting parent / number of children of parent
	ans is the sum of prop of visiting a leaf * distance
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

int n;
vector<vector<int> > g;
double ans;

void dfs(int u, int len, int p, double prop) {
	bool isleaf = 1;
	for (int i = 0; i < g[u].size(); i++) {
		if (p != g[u][i]) {
			isleaf = 0;
			dfs(g[u][i], len + 1, u, (double)prop / (g[u].size() - (u != 1)));
		}
	}
	if (isleaf) ans += len * prop;
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	loop(i, 0, n - 2) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0, -1, 1);
	printf("%.6lf", ans);
}