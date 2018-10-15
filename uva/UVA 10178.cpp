/*
	number of faces in a planer graph : 
	sum of 1 + edges - vertices for each connected component 
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

int n, m;
vector<vector<int> > g;
map<string, int> mp;
bool vis[N];
int used[500][500];
int edge, vert;

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	vert++;
	for (int i = 0; i < g[u].size(); i++) {
		if (used[g[u][i]][u] == 0 || used[u][g[u][i]] == 0) continue;
		edge++;
		used[g[u][i]][u]--;
		used[u][g[u][i]]--;
		dfs(g[u][i]);
	}
}

int main() {
	io;
	while (cin >> n >> m) {
		mp.clear();
		g.clear();
		g.resize(n + 1);
		int cnt = 1;
		memset(used, 0, sizeof used);
		loop(i, 0, m - 1) {
			string a, b;
			cin >> a >> b;
			if (!mp[a]) mp[a] = cnt++;
			if (!mp[b]) mp[b] = cnt++;
			g[mp[a]].push_back(mp[b]);
			g[mp[b]].push_back(mp[a]);
			used[mp[a]][mp[b]]++;
			used[mp[b]][mp[a]]++;
		}
		memset(vis, 0, sizeof vis);
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			edge = 0, vert = 0;
			if (!vis[i]) dfs(i), ans += 1 + edge - vert;
		}
		cout << ans << endl;
	}
}