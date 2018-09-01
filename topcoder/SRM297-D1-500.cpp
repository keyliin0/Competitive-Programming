/*
	try to put fields on top , bottom , right and left of the monster then backtrack and each time try to remove some fields 
	if it's not possibile to get out of the grid then minimize the answer with the current number of fields 
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

bool vis[50][50], visrow[50], viscol[50];
int n, m;
vector<pair<int, int> > p;
int ans = oo;
char g[50][50];


class CageTheMonster {
public:
	void bfs(int cnt,int xx,int yy) {
	queue<pair<int,int> > q;
	memset(vis, 0, sizeof vis);
	q.push({ xx,yy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (vis[x][y] || visrow[x] || viscol[y] || g[x][y] == '#') continue;
		vis[x][y] = 1;
		loop(i, 0, 3) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			q.push({ nx,ny });
		}
	}
		ans = min(ans, cnt);
	}

	void backtrack(int i,int cnt,int x,int y) {
	if (i == p.size()) {
		bfs(cnt, x, y);
		return;
	}
	if (p[i].first < 0 || p[i].first >= n || p[i].second < 0 || p[i].second >= m) {
		backtrack(i + 1, cnt, x, y);
		return;
	}
	if (i <= 1) {
		cnt++;
		visrow[p[i].first] = 1;
		backtrack(i + 1, cnt, x, y);
		visrow[p[i].first] = 0;
		cnt--;
		backtrack(i + 1, cnt, x, y);
	}
	else {
		cnt++;
		viscol[p[i].second] = 1;
		backtrack(i + 1, cnt, x, y);
		viscol[p[i].second] = 0;
		cnt--;
		backtrack(i + 1, cnt, x, y);
		}
	}
	int capture(vector<string> v) {
		n = v.size();
		m = v[0].size();
		loop(i, 0, n - 1)
			loop(j, 0, m - 1)
				g[i][j] = v[i][j];
		loop(i, 0, n - 1) {
			loop(j, 0, m - 1) {
				if (g[i][j] == '^') {
					p.clear();
					p.push_back({ i - 1,j });
					p.push_back({ i + 1,j });
					p.push_back({ i,j + 1 });
					p.push_back({ i ,j - 1 });
					backtrack(0, 0, i, j);
				}
			}
		}
		return (ans == oo ? -1 : ans);
	}
};