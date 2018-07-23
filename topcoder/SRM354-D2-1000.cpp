#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

ll dp[5][5][35];

class UnsealTheSafe {
public:
	ll solve(int r,int c,int d) {
		if (d == 0) return 1; // valid case
		ll &ret = dp[r][c][d];
		if (ret != -1) return ret;
		ret = 0;
		loop(i, 0, 3) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if ((nr == 4 && nc != 1) || nr > 4 || nr < 1 || nc > 3 || nc < 1) continue; // invalid case if we go outside the keypad
			ret += solve(nr, nc, d - 1); // try all 4 directions and take a digit
		}
		return ret;
	}
	ll countPasswords(int n) {
		memset(dp, -1, sizeof dp);
		ll ans = 0;
		loop(i, 1, 3)
			loop(j, 1, 3)
				ans += solve(i, j, n - 1); // each time try to start with one of the digits
		ans += solve(4, 1, n - 1); // start with a 0
		return ans;
	}
	
};