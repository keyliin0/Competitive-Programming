/*
	the problem can be solved using max flow 
	such that we can visit each node only 1 time 
	split the nodes and build the graph , connect all banks to the single source
	and borders of the city to the sink
	and if the max flow = b then its possible and no otherwise
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
//const int N = 1e6 + 5;
const ll mod = 1e5;
int oo = 1e9 + 7;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, b;

int in[55][55], out[55][55];

const int N = 5010;
vector<vector<int> > g;

int mat[N][N], p[N];
queue<int> q;
bool vis[N];

int maxFlow(int SOURCE, int SINK) {
	int res = 0;
	while (1) {
		memset(vis, 0, sizeof vis);
		while (!q.empty())
			q.pop();
		q.push(SOURCE);
		while (!q.empty()) {
			int src = q.front();
			q.pop();
			if (src == SINK)
				break;
			for (int i = 0; i < g[src].size(); i++) {
				int v = g[src][i];
				if (!vis[v] && mat[src][v] > 0) {
					vis[v] = 1;
					p[v] = src;
					q.push(v);
				}
			}
		}
		if (!vis[SINK])
			break;
		int f = oo;
		int cur = SINK;
		while (cur != SOURCE) {
			int prev = cur;
			cur = p[cur];
			f = min(mat[cur][prev], f);
		}
		res += f;
		cur = SINK;
		while (cur != SOURCE) {
			int prev = cur;
			cur = p[cur];
			mat[cur][prev] -= f;
			mat[prev][cur] += f;
		}
	}
	return res;
}

void addEdge(int u, int v, int cost) {
	g[u].push_back(v);
	g[v].push_back(u);
	mat[u][v] = cost;
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d%d", &n, &m, &b);
		g.clear();
		g.resize(5005);
		memset(mat, 0, sizeof mat);
		memset(vis, 0, sizeof vis);
		int cnt = 1;
		loop(i, 1, n) {
			loop(j, 1, m) {
				in[i][j] = cnt++;
				out[i][j] = cnt++;
				addEdge(in[i][j], out[i][j], 1);
			}
		}
		loop(i, 1, n) {
			loop(j, 1, m) {
				if (j + 1 <= m) addEdge(out[i][j], in[i][j + 1], oo);
				if (j - 1 >= 1) addEdge(out[i][j], in[i][j - 1], oo);
				if (i + 1 <= n) addEdge(out[i][j], in[i + 1][j], oo);
				if (i - 1 >= 1) addEdge(out[i][j], in[i - 1][j], oo);
			}
		}
		loop(i, 1, n) {
			addEdge(out[i][1],cnt, 1);
			addEdge(out[i][m], cnt, 1);
		}
		loop(i, 1, m ) {
			addEdge(out[1][i],cnt, 1);
			addEdge(out[n][i], cnt, 1);
		}
		loop(i, 1, b) {
			int x, y;
			scanf("%d%d", &x, &y);
			x = n - x + 1;
			addEdge(0, in[x][y], 1);
		}
		printf(maxFlow(0,cnt) == b ? "possible" : "not possible");
		printf("\n");
	}
}
