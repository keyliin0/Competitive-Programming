/*
	use mincut
	first node is the source
	connect sink with base nodes with weight values equal to min d * d from a gun to the base 
	connect each base to plants which are reachable with weight infinity 
	connect each plant to the sink with weight equal to min d * d from a gun to the plant
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
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

const int N = 205;
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

class GreenWarfare {
public:
	int dist(int x,int y,int xx,int yy) {
		return (x - xx) * (x - xx) + (y - yy) * (y - yy);
	}
	int findmindist(int x, int y, vector<int> & canonX, vector<int> & canonY) {
		int res = oo;
		for (int i = 0; i < canonX.size(); i++) {
			res = min(res, dist(x, y, canonX[i], canonY[i]));
		}
		return res;
	}
	int minimumEnergyCost(vector <int> canonX, vector <int> canonY,
		vector <int> baseX, vector <int> baseY,
		vector <int> plantX, vector <int> plantY,
		int energySupplyRadius) {
		g.resize(N);
		int n = baseX.size();
		int m = plantX.size();
		for (int i = 0, u = 1; i < n; i++, u++) {
			addEdge(0, u, findmindist(baseX[i], baseY[i], canonX, canonY));
		}
		for (int i = 0, u = 1; i < n; i++, u++) {
			for (int j = 0, v = n + 1; j < m; j++, v++) {
				if (dist(baseX[i], baseY[i], plantX[j], plantY[j]) <= energySupplyRadius * energySupplyRadius)
					addEdge(u, v, oo);
			}
		}
		for (int j = 0, v = n + 1; j < m; j++, v++)
			addEdge(v, n + m + 2, findmindist(plantX[j], plantY[j], canonX, canonY));
		return maxFlow(0, n + m + 2);
	}
};