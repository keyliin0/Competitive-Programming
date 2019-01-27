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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
char g[505][505];
int r, c, rr, cc;
bool reach;
bool vis[505][505];

bool valid(int x,int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x,int y) {
	if (x == rr && y == cc) {
		reach = 1;
		return;
	}
	vis[x][y] = 1;
	loop(i, 0, 3) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && !vis[nx][ny] && (g[nx][ny] == '.' || (nx == rr && ny == cc))) dfs(nx, ny);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		scanf("%s",g[i]);
	scanf("%d%d%d%d", &r, &c, &rr, &cc);
	r--;
	c--;
	rr--;
	cc--;
	dfs(r, c);
	if (!reach) {
		printf("NO");
		return 0;
	}
	int cnt = 0;
	loop(i, 0, 3) {
		int x = rr + dx[i];
		int y = cc + dy[i];
		if ((valid(x, y) && g[x][y] == '.') || (r == x && c == y)) cnt++;
	}
	if (r == rr && c == cc) {
		if(cnt >= 1) printf("YES");
		else printf("NO");
		return 0;
	}
	if (g[rr][cc] == 'X') cnt = 99;
	if (cnt >= 2) printf("YES");
	else printf("NO");
}