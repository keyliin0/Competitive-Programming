/*
	use kruskal to find MST
	find the cost from each node to other nodes and compare it to the cost array if they are diffrent then the ans is No
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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int p[2005];
vector<vector<pair<int,int >> > g;
int d[2005][2005];
int n;
bool ok = 1;

int find(int u) {
	if (p[u] == u)
		return u;
	return p[u] = find(p[u]);
}

void dfs(int u,int p,int s,int cost) {
	if (cost != d[s][u] || cost != d[u][s]) {
		ok = 0;
		return;
	}
	for (int i = 0; i < g[u].size(); i++) {
		if (p != g[u][i].first) {
			dfs(g[u][i].first, u, s, cost + g[u][i].second);
		}
	}
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	vector<pair<int, pair<int, int> > > edges;
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) {
			scanf("%d", &d[i][j]);
			if (i == j && d[i][j] || i != j && !d[i][j]) {
				printf("NO");
				return 0;
			}
			if (i != j) edges.push_back({ d[i][j] ,{ i , j} });
		}
		p[i] = i;
	}
	sort(edges.begin(), edges.end());
	for(int i= 0; i < edges.size() ;i ++){
		int a = find(edges[i].second.first);
		int b = find(edges[i].second.second);
		if (a == b) continue;
		p[a] = b;
		g[edges[i].second.first].push_back({ edges[i].second.second , edges[i].first });
		g[edges[i].second.second].push_back({ edges[i].second.first ,edges[i].first });
	}
	loop(i, 0, n - 1) {
		dfs(i, -1, i, 0);
	}
	if (ok) printf("YES");
	else printf("NO");
}