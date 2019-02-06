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

int n, h, m;
int const MAX = 10005;
bool hotel[MAX];
int H[105];
vector<vector<pair<int, int> > > g;
vector<vector<int> > g2;
int cost[MAX];
bool vis[MAX];

void dijkstra(int s) {
	loop(i, 1, n)
		cost[i] = oo;
	priority_queue<pair<int, int> > q;
	cost[s] = 0;
	q.push({ 0,s });
	while (!q.empty()) {
		int u = q.top().second;
		int c = -q.top().first;
		if (u > s && c <= 600 && (hotel[u] || u == n)) {
			g2[s].push_back(u);
			g2[u].push_back(s);
		}
		q.pop();
		if (cost[u] < c) continue;
		for (int i = 0; i < g[u].size(); i++) {
			if (c + g[u][i].second < cost[g[u][i].first]) {
				cost[g[u][i].first] = c + g[u][i].second;
				q.push({ -cost[g[u][i].first] , g[u][i].first });
			}
		}
	}
}

int bfs(int s) {
	queue<pair<int, int> > q;
	q.push({ 0,s });
	while (!q.empty()) {
		int u = q.front().second;
		int c = q.front().first;
		if (u == n) return c - 1;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g2[u].size(); i++) {
			if (!vis[g2[u][i]]) {
				q.push({ c + 1,g2[u][i] });
			}
		}
	}
	return -1;
}

int main() {
	while (scanf("%d", &n) && n) {
		g.clear();
		g2.clear();
		g.resize(n + 1);
		g2.resize(n + 1);
		scanf("%d", &h);
		memset(hotel, 0, sizeof hotel);
		loop(i, 0, h - 1) {
			scanf("%d", &H[i]);
			hotel[H[i]] = 1;
		}
		scanf("%d", &m);
		loop(i, 0, m - 1) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}
		dijkstra(1);
		//dijkstra(n);
		loop(i, 0, h - 1) {
			if (H[i] != 1 && H[i] != n) dijkstra(H[i]);
		}
		memset(vis, 0, sizeof vis);
		int ans = bfs(1);
		printf("%d\n", ans);
	}
}