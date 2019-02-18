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
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
char g[55][55];
bool vis[55][55];

int p;
void dfs(int x,int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || g[x][y] == '.') return;
	p++;
	vis[x][y] = 1;
	loop(i, 0, 3) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
}

int main() {
	cin >> n >> m;
	int cnt = 0;
	loop(i,0,n-1)
		loop(j, 0, m - 1) {
			cin >> g[i][j];
			cnt += g[i][j] != '.';
	}
	if (cnt < 3) {
		cout << -1;
		return 0;
	}
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			if (g[i][j] == '.') continue;
			g[i][j] = '.';
			bool done = 0;
			loop(ii, 0, n - 1) {
				loop(jj, 0, m - 1) {
					if (g[ii][jj] == '#') {
						p = 0;
						memset(vis, 0, sizeof vis);
						dfs(ii, jj);
						done = 1;
						break;
					}
				}
				if (done) break;
			}
			if (p != cnt - 1) {
				cout << 1;
				return 0;
			}
			g[i][j] = '#';
		}
	}
	cout << 2;
}