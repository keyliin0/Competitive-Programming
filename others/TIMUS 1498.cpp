/*
	get shortest path to all cells
	now we know if we can reach the demon with <= l horizontally or vertically
	check the cells which are in the same row with the demon , below and above
	do the same vertically (cols)
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

int n, m, l, xi, xx, yy, yi;
int cost[105][105];

int main() {
	scanf("%d%d%d%d%d%d%d", &n, &m, &l, &xi, &yi, &xx, &yy);
	queue<pair<pair<int, int>, int> > q;
	q.push({ { xi,yi },0 });
	loop(i, 1, n)
		loop(j, 1, m)
		cost[i][j] = oo;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		q.pop();
		if (c >= cost[x][y] || (x == xx && y == yy) ) continue;
		cost[x][y] = c;
		loop(i, 0, 3) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			q.push({ { nx,ny },c + 1 });
		}
	}
	int ans = 0;
	loop(i, 1, n) {
		if(yy - 1 >=  1 && cost[i][yy - 1] + abs(i - xx) <= l) ans = max(ans, abs(i - xx) + 1);
		if (yy + 1 <= m && cost[i][yy + 1] + abs(i - xx) <= l) ans = max(ans, abs(i - xx) + 1);
		if (cost[i][yy] + abs(i - xx) - 1 <= l) ans = max(ans, abs(i - xx));
	}
	loop(j, 1, m) {
		if (xx - 1 >= 1 && cost[xx - 1][j] + abs(j - yy) <= l) ans = max(ans, abs(j - yy) + 1);
		if (xx + 1 <= n && cost[xx + 1][j] + abs(j - yy) <= l) ans = max(ans, abs(j - yy) + 1);
		if (cost[xx][j] + abs(j - yy) - 1 <= l) ans = max(ans, abs(j - yy ));
	}
	printf("%d", ans);
}