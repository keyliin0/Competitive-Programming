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

int n, m;
char g[1005][1005], g2[1005][1005];

bool can(int x, int y) {
	if (x + 1 >= n || y + 1 >= m || x - 1 < 0 || y - 1 < 0) return 0;
	loop(i, 0, 7) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (g[nx][ny] == '.') return 0;
	}
	return 1;
}


int main() {
	io;
	cin >> n >> m;
	loop(i, 0, n - 1)
		loop(j, 0, m - 1) {
			cin >> g[i][j];
			g2[i][j] = '.';
	}
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			if (can(i,j)) {
				loop(k, 0, 7)
					g2[i + dx[k]][j + dy[k]] = '#';
			}
		}
	}
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
		if (g2[i][j] != g[i][j]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
}