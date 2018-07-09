/* 
	we run dfs from each non visited empty cell
	suppose that empty cells are one connected component 
	if this component is surrounded with black cells then we add their number to the black pts
	otherwise we add them to the white pts
	if it's surrounded by both black and white then we ignore this component
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n = 9;
int black, white,cnt;
char g[10][10];
bool vis[10][10];

void dfs(int x, int y) {
	if (g[x][y] == 'X') {
		black = 1;
		return;
	}
	if (g[x][y] == 'O') {
		white = 1;
		return;
	}
	if (vis[x][y]) return;
	vis[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny >= n || ny < 0) continue;
		dfs(nx, ny);
	}
}

int main() {
	int t;
	io;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		int b = 0, w = 0;
		loop(i, 0, 8)
			loop(j, 0, 8) {
				cin >> g[i][j];
				b += g[i][j] == 'X';
				w += g[i][j] == 'O';
		}
		loop(i,0,8)
			loop(j, 0, 8) {
				if (g[i][j] != '.' || vis[i][j]) continue;
				cnt = black = white = 0;
				dfs(i, j);
				if (black && !white) b += cnt;
				else if (white && !black) w += cnt;
		}
 		cout << "Black " << b << " White " << w << endl;
	}
}