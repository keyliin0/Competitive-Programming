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
 
int n, m;
int t[N];
int low[505][505];
int pos[505];
ll dp[505][505];
ll MOD = 998244353;
 
ll solve(int l, int r) {
	if (l >= r) return 1;
	ll &ret = dp[l][r];
	if (ret != -1) return ret;
	int p = pos[low[l][r]];
	ll a = 0, b = 0;
	for (int i = p; i <= r; i++) {
		a += (solve(p + 1, i) * solve(i + 1, r)) % MOD;
		a %= MOD;
	}
	for (int i = p; i >= l; i--) {
		b += (solve(i, p - 1) * solve(l, i - 1)) % MOD;
		b %= MOD;
	}
	ret = (a * b) % MOD;
	return ret;
}
 
int main() {
	scanf("%d%d", &n, &m);
	loop(i, 1, n) {
		scanf("%d", &t[i]);
		pos[t[i]] = i;
	}
	loop(i, 1, n) {
		int mn = t[i];
		loop(j, i, n) {
			mn = min(mn, t[j]);
			low[i][j] = mn;
		}
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(1, n);
	cout << ans;
}