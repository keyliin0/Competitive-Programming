/* 
	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/SPOJ/SPOJ_CATM.txt
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

int n, m;
int cost[200][200];

bool bfs(int xx, int yy, bool mouse) {
	queue<pair<int, int> > q;
	q.push({ xx,yy });
	cost[xx][yy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (x == 0 || x == n + 1 || y == 0 || y == m + 1) {
			if (mouse) return 1;
			continue;
		}
		loop(i, 0, 3) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (cost[x][y] + 1 < cost[nx][ny]) {
				cost[nx][ny] = cost[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return 0;
}

int main() {
	int tests;
	scanf("%d%d%d", &n, &m,&tests);
	while (tests--) {
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= m + 1; j++)
				cost[i][j] = oo;
		int x, y, x1, x2, y1, y2;
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		bfs(x1, y1,0);
		bfs(x2, y2, 0);
		bool yes = bfs(x, y, 1);
		if (yes) printf("YES\n");
		else printf("NO\n");
	}
}