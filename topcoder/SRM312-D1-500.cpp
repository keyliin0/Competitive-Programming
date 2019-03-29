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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

const int N = 105;

int n, m, idx[N], low[N], T;
vector<vector<int> > g, g2;
vector<int> S;
bool vis[N];
int compID[N], sz[N], cmp;
int val[N], in[N];

void DFS(int u) {
	idx[u] = low[u] = ++T;
	S.push_back(u);
	vis[u] = true;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (idx[v] == 0)
			DFS(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (idx[u] == low[u]) {
		while (true) {
			int v = S.back();
			S.pop_back();
			vis[v] = false;
			compID[v] = cmp;
			sz[cmp]++;
			if (v == u)
				break;
		}
		++cmp;
	}
}


class AntarcticaPolice {
public:
	double minAverageCost(vector <int> costs, vector <string> roads) {
		g.resize(roads.size() + 1);
		g2.resize(roads.size() + 1);
		for (int i = 0; i < roads.size(); i++) {
			for (int j = 0; j < roads.size(); j++) {
				if (i == j) continue;
				if (roads[i][j] == 'Y')
					g[i].push_back(j);
			}
		}
		for (int i = 0; i < roads.size(); i++)
			if (!idx[i]) DFS(i);
		for (int i = 0; i < cmp; i++)
			val[i] = oo;
		for (int i = 0; i < roads.size(); i++) {
			val[compID[i]] = min(val[compID[i]], costs[i]);
			for (int j = 0; j < g[i].size(); j++) {
				if (compID[i] != compID[g[i][j]]) {
					g2[compID[i]].push_back(compID[g[i][j]]);
					in[compID[g[i][j]]]++;
				}
			}
		}
		int cnt = 0, cst = 0;
		vector<int> v;
		for (int i = 0; i < cmp; i++) {
			if (in[i] == 0) cst += val[i], cnt++;
			else v.push_back(val[i]);
		}
		double ans = (double)cst / cnt;
		while (v.size()) {
			double curr = (double)cst / cnt;
			int x = -1;
			for (int i = 0; i < v.size(); i++) {
				double c = (double)(cst + v[i]) / (cnt + 1);
				if (c < curr) curr = c, x = i;
			}
			if (x == -1) break;
			if (ans > curr) {
				ans = curr;
				cnt++;
				cst += v[x];
				v.erase(v.begin() + x);
			}
			else break;
		}
		return ans;
	}
};
