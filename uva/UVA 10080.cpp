/*
	if a gopher can reach a hole within s seconds then put an egde between them
	it's obvious we will obtain a bipartite graph and we need max matching
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
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


const int N = 305;
vector<vector<int> > g;
int n, m;
double s, v;
point t1[N], t2[N];

int mat[N][N], p[N];
queue<int> q;
bool vis[N];
int maxFlow(int SOURCE,int SINK) {
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
	while (scanf("%d%d%lf%lf", &n,&m,&s,&v) != EOF) {
		g.clear();
		g.resize(N);
		memset(mat, 0, sizeof mat);
		memset(p, 0, sizeof p);
		for (int i = 1; i <= n; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			addEdge(0, i, 1);
			t1[i] = point(x, y);
		}
		for (int i = 1; i <= m; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			t2[i] = point(x, y);
			addEdge(n + i, n + m + 1, 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (sqrt(norm(t1[i] - t2[j])) / v <= s)
					addEdge(i, n + j, 1);
			}
		}
		printf("%d\n", n-maxFlow(0, n + m + 1));
	}
}
