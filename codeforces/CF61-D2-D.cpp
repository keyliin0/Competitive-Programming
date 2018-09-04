/*
	need to traverse all edges twice except the roads from the root to the city with max sum
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


vector <vector<pair<int, int> > > g;
int n;
ll mx_cost = 0;

void dfs(int u, int p,ll curr) {
	for (int i = 0; i < g[u].size(); i++) {
		if(g[u][i].first != p) dfs(g[u][i].first, u, curr + g[u][i].second);
	}
	mx_cost = max(mx_cost, curr);
}


int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	ll sum = 0;
	loop(i, 1, n - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
		sum += c;
	}
	dfs(1, -1, 0);
	printf("%lld",sum * 2 - mx_cost);
}