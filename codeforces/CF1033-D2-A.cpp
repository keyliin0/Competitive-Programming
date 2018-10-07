/*
	mark the cells that the queen can attack as visited
	run dfs from the king position and check if he can reach the desired coordinates
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

int n, ax, ay, bx, by, cx, cy;
bool vis[1011][1011];
bool yes = 0;

void dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > n || vis[x][y]) return;
	vis[x][y] = 1;
	if (x == cx && y == cy) yes = 1;
	loop(i, 0, 7) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!vis[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	scanf("%d%d%d%d%d%d%d", &n, &ax, &ay, &bx, &by, &cx, &cy);
	int x1 = ax, x2 = ax, y = ay ;
	while (y <= n) {
		if (x1 <= n) vis[x1][y] = 1;
		if (x2 >= 1) vis[x2][y] = 1;
		y++;
		x1++;
		x2--;
	}
	x1 = ax, x2 = ax, y = ay;
	while (y >= 1) {
		if (x1 <= n) vis[x1][y] = 1;
		if (x2 >= 1) vis[x2][y] = 1;
		y--;
		x1++;
		x2--;
	}
	loop(i, 1, n) vis[ax][i] = vis[i][ay] = 1;
	dfs(bx, by);
	if (yes) printf("YES");
	else printf("NO");
}