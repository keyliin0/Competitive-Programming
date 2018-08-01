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

int n,m,s,e;
vector<vector<pair<int, int> > > g;
int dist[N];


int main() {
	int test;
	cin >> test;
	while (test--) {
		scanf("%d%d%d%d",&n,&m,&s,&e);
		g.clear();
		g.resize(n + 1);
		loop(i, 0, m - 1) {
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}
		loop(i, 1, n)
			dist[i] = oo;
		priority_queue<pair<int,int> > q;
		q.push({ 0,s });
		dist[s] = 0;
		while (!q.empty()) {
			int u = q.top().second;
			int c = -q.top().first;
			q.pop();
			if (c > dist[u]) continue;
			for (int i = 0; i < g[u].size(); i++) {
				if (c + g[u][i].second < dist[g[u][i].first]) {
					dist[g[u][i].first] = c + g[u][i].second;
					q.push({ -dist[g[u][i].first],g[u][i].first });
				}
			}
		}
		if (dist[e] == oo) printf("NONE\n");
		else printf("%d\n",dist[e]);
	}
}