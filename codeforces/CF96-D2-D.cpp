/*
	build a new graph
	first use dijkstra to find if you can reach a node v when taking a taxi from a node u
	if it is possible then push an edge from u to v with the cost Cu and so on
	do that to all nodes
	then run dijkstra on the new graph to find the minimum cost
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

int n, m, x, y;
ll cost[1005];
vector<vector<pair<int, ll> > > g1,g2;
pair<ll, ll> t[1005];

void dijkstra1(int u) {
	loop(i, 1, n)
		cost[i] = 1e18;
	cost[u] = 0;
	priority_queue<pair<ll, int> > q;
	q.push({ 0,u });
	while (!q.empty()) {
		int node = q.top().second;
		ll c = -q.top().first;
		q.pop();
		if (cost[node] < c) continue;
		if(u != node) g2[u].push_back({ node,t[u].second });
		for (int i = 0; i < g1[node].size(); i++) {
			if (c + g1[node][i].second < cost[g1[node][i].first] && c + g1[node][i].second <= t[u].first) {
				cost[g1[node][i].first] = c + g1[node][i].second;
				q.push({ -cost[g1[node][i].first] , g1[node][i].first });
			}
		}
	}
}

void dijkstra2() {
	loop(i, 1, n)
		cost[i] = 1e18;
	cost[x] = 0;
	priority_queue<pair<ll, int> > q;
	q.push({ 0,x });
	while (!q.empty()) {
		int u = q.top().second;
		ll c = -q.top().first;
		q.pop();
		if (cost[u] < c) continue;
		for (int i = 0; i < g2[u].size(); i++) {
			if (c + g2[u][i].second < cost[g2[u][i].first]) {
				cost[g2[u][i].first] = c + g2[u][i].second;
				q.push({ -cost[g2[u][i].first] , g2[u][i].first });
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d",&n,&m,&x,&y);
	g1.resize(n + 1);
	g2.resize(n + 1);
	loop(i, 0, m - 1) {
		int a, b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		g1[a].push_back({ b,c });
		g1[b].push_back({ a,c });
	}
	loop(i, 1, n)
		scanf("%lld%lld",&t[i].first,&t[i].second);
	loop(i, 1, n)
		dijkstra1(i);
	dijkstra2();
	if (cost[y] == 1e18) printf("-1");
	else printf("%lld",cost[y]);
}