/*
	detect if there is a cycle first
	otherwise use dp to solve the problem
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int dp[505][505];
int n, m;
char g[55][55];
int vis[55][55];
bool f;

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'H') return;
	if (vis[x][y] == 1) {
		f = 1;
		return;
	}
	if (vis[x][y] == 2) return;
	vis[x][y] = 1;
	int step = g[x][y] - '0';
	dfs(x + step, y);
	dfs(x - step, y);
	dfs(x, y + step);
	dfs(x, y - step);
	vis[x][y] = 2;
}

int solve(int x,int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'H') return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = -oo;
	int step = g[x][y] - '0';
	ret = max(ret, 1 + solve(x + step, y));
	ret = max(ret, 1 + solve(x - step, y));
	ret = max(ret, 1 + solve(x, y + step));
	ret = max(ret, 1 + solve(x, y - step));
	return ret;
}

class JumpingBoard {
public:
	int maxJumps(vector <string> board) {
		n = board.size();
		m = board[0].size();
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
				g[i][j] = board[i][j];
		dfs(0, 0);
		if (f) return -1;
		memset(dp, -1, sizeof dp);
		int ans = solve(0, 0);
		return ans >= oo ? -1 : ans;
	}
};

