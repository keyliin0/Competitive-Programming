/*
	a classic dp would work easily if there are no cycles 
	since all the values are positive and we need to maximize the result
	we can use SCC to remove cycles from the graph and the value of a comp 
	is the sum of all values of its nodes 
	then we can use dp
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
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, idx[N], low[N], T;
vector<vector<int> > g, g2;
vector<int> S;
bool vis[N];
int compID[N], sz[N], cmp;
int id[500][500];
int val[500];
int cmpval[500];

int dp[500];

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


class MarbleCollectionGame {
public:
	int solve(int u) {
		int &ret = dp[u];
		if (ret != -1) return ret;
		ret = 0;
		for (auto v : g2[u]) {
			ret = max(ret, cmpval[v] + solve(v));
		}
		return ret ;
	}
	int collectMarble(vector<string> board) {
		g.resize(500);
		int cnt = 1;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				id[i][j] = cnt++;
				if (isdigit(board[i][j])) val[id[i][j]] = board[i][j] - '0';
			}
		}
		int n = board.size(), m = board[0].size();
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == '#') continue;
				if (i + 1 < n && board[i + 1][j] != '#') g[id[i][j]].push_back(id[i + 1][j]);
				if (j + 1 < m && board[i][j + 1] != '#') g[id[i][j]].push_back(id[i][j + 1]);
				if (i - 1 >= 0 && board[i][j] == 'U' && board[i - 1][j] != '#') g[id[i][j]].push_back(id[i - 1][j]);
				if (j - 1 >= 0 && board[i][j] == 'L' && board[i][j - 1] != '#') g[id[i][j]].push_back(id[i][j - 1]);
			}
		}
		for (int u = 1; u < cnt; u++)
			if(!idx[u])
				DFS(u);
		g2.resize(cmp);
		for (int u = 1; u < cnt; u++) {
			cmpval[compID[u]] += val[u];
			for (auto v : g[u]) {
				if (compID[v] != compID[u]) {
					g2[compID[u]].push_back(compID[v]);
				}
			}
		}
		memset(dp, -1, sizeof dp);
		return cmpval[compID[1]] + solve(compID[1]);
	}
};