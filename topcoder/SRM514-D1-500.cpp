/*
	https://apps.topcoder.com/wiki/display/tc/SRM+514
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
#define logg2  0.30102999566398119521373889472449L
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

ll f[15][15][2];
ll dp[1 << 10][15];
ll C[15][1 << 10];
int n, m;

class MagicalGirlLevelTwoDivOne {
public:
	ll solve(int mask, int i) {
		if (i == n) return mask == (1 << m) - 1;
		ll &ret = dp[mask][i];
		if (ret != -1) return 0;
		ret = 0;
		for (int j = 0; j < (1 << m); j++) {
			ret += (C[i][j] * solve(mask ^ j, i + 1)) % mod;
			ret %= mod;
		}
		return ret;
	}
	int cnt(int mask) {
		int res = 0;
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) res++;
		}
		return res % 2;
	}
	int theCount(vector <string> p, int nn, int mm) {
		n = nn;
		m = mm;
		int r = p.size();
		int c = p[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f[i][j][0] = 1;
				f[i][j][1] = 1;
				for (int ii = i; ii < r; ii += n) {
					for (int jj = j; jj < c; jj += m) {
						if (p[ii][jj] == '.') {
							f[i][j][1] *= 5;
							f[i][j][1] %= mod;
							f[i][j][0] *= 4;
							f[i][j][0] %= mod;
						}
						else if ((p[ii][jj] - '0') % 2 == 0) {
							f[i][j][1] = 0;
						}
						else f[i][j][0] = 0;

					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int mask = 0; mask < (1 << m); mask++) {
				if (!cnt(mask)) continue;
				C[i][mask] = 1;
				for (int j = 0; j < m; j++) {
					if (mask & (1 << j)) C[i][mask] *= f[i][j][1];
					else C[i][mask] *= f[i][j][0];
					C[i][mask] %= mod;
				}
			}
		}
		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0);
		return (int)ans;
	}
};
