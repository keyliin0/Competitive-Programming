/*
	try all cases while matching each pipe with the right one
	and memoize
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

int m;
char g[3][1005];
bool active[3][1005];
ll dp[3][1005][5];

ll traverse(int x,int y,int last) {
	if (x >= 3 || y >= m || x < 0 || y < 0 || active[x][y] || g[x][y] == '#') return 0;
	ll &ret = dp[x][y][last];
	if (ret != -1) return ret;
	ret = 0;
	active[x][y] = 1;
	if (last == 1) {
		if (y + 1 == m && x == 2) ret++;
		else {
			ret += traverse(x, y + 1, 3);
			ret += traverse(x, y + 1, 4);
		}
		ret += traverse(x - 1, y, 2);
		ret += traverse(x - 1, y, 3);
		ret %= mod;
	}
	if (last == 2) {
		ret += traverse(x + 1, y, 1);
		ret += traverse(x + 1, y, 4);
		if (y + 1 == m && x == 2) ret++;
		else {
			ret += traverse(x, y + 1, 3);
			ret += traverse(x, y + 1, 4);
		}
		ret %= mod;
	}
	if (last == 3) {
		ret += traverse(x + 1, y, 1);
		ret += traverse(x + 1, y, 4);
		ret += traverse(x , y - 1, 1);
		ret += traverse(x , y - 1, 2);
		ret %= mod;
	}
	if (last == 4) {
		ret += traverse(x - 1, y, 2);
		ret += traverse(x - 1, y, 3);
		ret += traverse(x , y - 1, 1);
		ret += traverse(x , y - 1, 2);
		ret %= mod;
	}
	active[x][y] = 0;
	return ret;
}

int main() {
	io;
	int cases;
	cin >> cases;
	loop(test, 1, cases) {
		cin >> m;
		loop(i, 0, 2)
			loop(j, 0, m - 1)
			cin >> g[i][j];
		memset(dp, -1, sizeof dp);
		ll ans = traverse(0, 0, 3);
		cout << "Case #" << test << ": " << ans << endl;
	}
}