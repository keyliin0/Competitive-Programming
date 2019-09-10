#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll cst[305][305];
int n, m, k;
ll dp[305][305];

ll solve(int i,int rem) {
	if (rem <= 0) return 0;
	if (i == n) return 1e18;
	ll &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = solve(i + 1, rem);
	loop(j, i, n - 1) {
		if (cst[i][j]) ret = min(ret, cst[i][j] + solve(j + 1, rem - (j - i + 1)));
	}
	return ret;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	loop(i, 0, m - 1) {
		int l, r;
		ll c;
		scanf("%d%d%lld",&l,&r,&c);
		l--;
		r--;
		if (!cst[l][r]) cst[l][r] = c;
		else cst[l][r] = min(cst[l][r], c);
	}
	loop(i, 1, n - 1) {
		loop(j, i, n - 1) {
			if (cst[i - 1][j]) {
				if (!cst[i][j]) cst[i][j] = cst[i - 1][j];
				else cst[i][j] = min(cst[i][j], cst[i - 1][j]);
			}
		}
	}
	memset(dp, -1, sizeof dp);
	cout << (solve(0, k) == 1e18 ? -1 : solve(0, k));
}