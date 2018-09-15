/*
	find all shortest paths from source to all nodes 
	reverse the graph and do the same for the destination
	now try every edge if the cost from the node connected to this edge to the source + cost to the destination <= p
	maximize the weight of this edge with the ans
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

int n, m, s, t, p;
ll cost1[N],  cost2[N];
vector<vector<pair<int, int> > > g1, g2;

void dijkstra1() {
	loop(i, 0, n + 1) {
		cost1[i] = 1e18;
	}
	priority_queue<pair<ll, int> > q;
	q.push({ 0 , s });
	cost1[s] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		ll c = -q.top().first;
		q.pop();
		if (cost1[u] < c) continue;
		for (int i = 0; i < g1[u].size(); i++) {
			if (c + g1[u][i].second <= cost1[g1[u][i].first]) {
				cost1[g1[u][i].first] = c + g1[u][i].second;
				q.push({ -(c + g1[u][i].second) ,g1[u][i].first });
			}
		}
	}
}

void dijkstra2() {
	loop(i, 0, n + 1) {
		cost2[i] = 1e18;
	}
	priority_queue<pair<ll, int> > q;
	q.push({ 0 , t });
	cost2[t] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		ll c = -q.top().first;
		q.pop();
		if (cost2[u] < c) continue;
		for (int i = 0; i < g2[u].size(); i++) {
			if (c + g2[u][i].second <= cost2[g2[u][i].first]) {
				cost2[g2[u][i].first] = c + g2[u][i].second;
				q.push({ -(c + g2[u][i].second) ,g2[u][i].first });
			}
		}
	}
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		g1.clear();
		g2.clear();
		g1.resize(n + 1);
		g2.resize(n + 1);
		loop(i, 0, m - 1) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			g1[a].push_back({ b,c });
			g2[b].push_back({ a,c });
		}
		dijkstra1();
		dijkstra2();
		int ans = -1;
		loop(u, 1, n) {
			if (cost1[u] == 1e18) continue;
			for (int i = 0; i < g1[u].size(); i++) {
				if (cost2[g1[u][i].first] == 1e18 || cost1[u] + g1[u][i].second  + cost2[g1[u][i].first] > p) continue;
				ans = max(ans, g1[u][i].second);
			}
		}
		printf("%d\n",ans);
	}
}