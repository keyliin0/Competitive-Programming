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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll dp[2005];
int mx[N];
int n, m, k;
ll t[N];

ll solve(int i) {
	if (i == k + 1) return 0;
	ll &ret = dp[i];
	if (ret != -1) return ret;
	ret = 1e18;
	for (int j = i; j <= k; j++) {
		int x = mx[j - i + 1];
		if(x) ret = min(ret, t[j] - t[i - 1] - (t[i - 1 + x] - t[i - 1]) + solve(j + 1));
		else ret = min(ret, t[j] - t[i - 1]  + solve(j + 1));
	}
	return ret;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	loop(i, 1, n) {
		scanf("%lld", &t[i]);
	}
	sort(t + 1, t + n + 1);
	loop(i, 1, n)
		t[i] += t[i - 1];
	while (m--) {
		int x, y;
		scanf("%d%d",&x,&y);
		mx[x] = max(mx[x], y);
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(1);
	cout << ans;
}