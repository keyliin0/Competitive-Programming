/*
	we need to find max matching between devices and plugs
	so we connect each device to the corresponding plug using an edge of weight 1
	if there is an adapter x y the relation is we can transform plug y to x 
	so make an edge from plug y to x with weight equal to infinity
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

const int N = 505;
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
	io;	
	int t;
	cin >> t;
	bool f = 0;
	while (t--) {
		memset(mat, 0, sizeof mat);
		g.clear();
		g.resize(N);
		int n, m, k;
		cin >> n;
		map<string, int> device, plug;
		int freq[505];
		memset(freq, 0, sizeof freq);
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (!plug[s]) {
				plug[s] = cnt++;
			}
			freq[plug[s]]++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (!device[s1]) {
				device[s1] = cnt++;
			}
			if (!plug[s2]) {
				plug[s2] = cnt++;
			}
			addEdge(plug[s2], device[s1], 1);
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (!plug[s1]) {
				plug[s1] = cnt++;
			}
			if (!plug[s2]) {
				plug[s2] = cnt++;
			}
			addEdge(plug[s2], plug[s1], oo);
		}
		for (auto it : device) {
			addEdge(it.second, cnt, 1);
		}
		for (auto it : plug) {
			if(freq[it.second]) addEdge(0, it.second, freq[it.second]);
		}
		if (f) cout << "\n";
		f = 1;
		cout << m - maxFlow(0, cnt) << "\n";
	}
}