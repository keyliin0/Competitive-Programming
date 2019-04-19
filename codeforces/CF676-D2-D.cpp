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

/*
   0
 3	 1
   2
*/

int n, m;
char g[1005][1005];
int cst[1005][1005][4];
int x, y, xx, yy;

bool can(char c,int m,int r) {
	if (c == '+') return 1;
	if (c == '-') {
		if ((r == 0 || r == 2) && (m == 3 || m == 1)) return 1;
		if ((r == 1 || r == 3) && (m == 0 || m == 2)) return 1;
		return 0;
	}
	if (c == '|') {
		if ((r == 0 || r == 2) && (m == 0 || m == 2)) return 1;
		if ((r == 1 || r == 3) && (m == 3 || m == 1)) return 1;
		return 0;
	}
	if (c == '^') {
		if (r == 0 && m == 0) return 1;
		if (r == 1 && m == 1) return 1;
		if (r == 2 && m == 2) return 1;
		if (r == 3 && m == 3) return 1;
		return 0;
	}
	if (c == '>') {
		if (r == 0 && m == 1) return 1;
		if (r == 1 && m == 2) return 1;
		if (r == 2 && m == 3) return 1;
		if (r == 3 && m == 0) return 1;
		return 0;
	}
	if (c == '<') {
		if (r == 0 && m == 3) return 1;
		if (r == 1 && m == 0) return 1;
		if (r == 2 && m == 1) return 1;
		if (r == 3 && m == 2) return 1;
		return 0;
	}
	if (c == 'v') {
		if (r == 0 && m == 2) return 1;
		if (r == 1 && m == 3) return 1;
		if (r == 2 && m == 0) return 1;
		if (r == 3 && m == 1) return 1;
		return 0;
	}
	if (c == 'L') {
		if (r == 0 && m == 3) return 0;
		if (r == 1 && m == 0) return 0;
		if (r == 2 && m == 1) return 0;
		if (r == 3 && m == 2) return 0;
		return 1;
	}
	if (c == 'R') {
		if (r == 0 && m == 1) return 0;
		if (r == 1 && m == 2) return 0;
		if (r == 2 && m == 3) return 0;
		if (r == 3 && m == 0) return 0;
		return 1;
	}
	if (c == 'U') {
		if (r == 0 && m == 0) return 0;
		if (r == 1 && m == 1) return 0;
		if (r == 2 && m == 2) return 0;
		if (r == 3 && m == 3) return 0;
		return 1;
	}
	if (c == 'D') {
		if (r == 0 && m == 2) return 0;
		if (r == 1 && m == 3) return 0;
		if (r == 2 && m == 0) return 0;
		if (r == 3 && m == 1) return 0;
		return 1;
	}
	return 0;
}

bool out(int x,int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		scanf("%s", g[i]);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			loop(r, 0, 3)
				cst[i][j][r] = oo;
	scanf("%d%d%d%d",&x,&y,&xx,&yy);
	x--, y--, xx--, yy--;
	priority_queue<pair<pair<int,int>, pair<int, int> > > q;
	q.push({ {0,0},{x,y} });
	cst[x][y][0] = 0;
	while (!q.empty()) {
		int c = -q.top().first.first;
		int r = q.top().first.second;
		r %= 4;
		pair<int, int> u = q.top().second;
		q.pop();
		if (cst[u.first][u.second][r] < c) continue;
		if (c + 1 < cst[u.first][u.second][(r + 1) % 4]) {
			cst[u.first][u.second][(r + 1) % 4] = c + 1;
			q.push({ {-(c + 1),r + 1},u });
		}
		if (out(u.first - 1, u.second) && can(g[u.first][u.second], 0, r) && can(g[u.first - 1][u.second], 2, r)) {
			if (c + 1 < cst[u.first - 1][u.second][r]) {
				cst[u.first - 1][u.second][r] = c + 1;
				q.push({ {-cst[u.first - 1][u.second][r] ,r},{u.first - 1,u.second} });
			}
		}
		if (out(u.first + 1, u.second) && can(g[u.first][u.second], 2, r) && can(g[u.first + 1][u.second], 0, r)) {
			if (c + 1 < cst[u.first + 1][u.second][r]) {
				cst[u.first + 1][u.second][r] = c + 1;
				q.push({ {-cst[u.first + 1][u.second][r] ,r},{u.first + 1,u.second} });
			}
		}
		if (out(u.first, u.second - 1) && can(g[u.first][u.second], 3, r) && can(g[u.first][u.second - 1], 1, r)) {
			if (c + 1 < cst[u.first][u.second - 1][r]) {
				cst[u.first][u.second - 1][r] = c + 1;
				q.push({ {-cst[u.first][u.second - 1][r] ,r},{u.first ,u.second - 1} });
			}
		}
		if (out(u.first, u.second + 1) && can(g[u.first][u.second], 1, r) && can(g[u.first][u.second + 1], 3, r)) {
			if (c + 1 < cst[u.first][u.second + 1][r]) {
				cst[u.first][u.second + 1][r] = c + 1;
				q.push({ {-cst[u.first][u.second + 1][r] ,r},{u.first ,u.second + 1} });
			}
		}
	}
	int ans = oo;
	loop(r, 0, 3)
		ans = min(ans, cst[xx][yy][r]);
	printf("%d",ans == oo ? -1 : ans);
}