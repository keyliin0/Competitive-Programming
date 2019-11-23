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

pair<ll,pair<ll, ll> > t[505];
int n;
ll dp[505][505];

ll solve(int i, int take) {
	if (i == n) return 0;
	ll &ret = dp[i][take];
	if (ret != -1) return ret;
	ret = -1e18;
	ret = max(ret, solve(i + 1, take));
	ret = max(ret, t[i].second.first - t[i].first * t[i].second.second + solve(i + 1, take));
	ret = max(ret, t[i].second.first - t[i].first * take + solve(i + 1, take + 1));
	return ret;
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%lld%lld%lld", &t[i].second.first, &t[i].first, &t[i].second.second);
	}
	sort(t, t + n);
	reverse(t, t + n);
	ll ans = -1;
	memset(dp, -1, sizeof dp);
	loop(i, 0, n)
		ans = max(ans, solve(0, i));
	printf("%lld",ans);
}