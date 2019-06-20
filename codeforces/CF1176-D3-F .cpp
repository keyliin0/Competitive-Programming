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

int n;
vector<ll> cards[200005][3];

ll dp[200005][11];

ll solve(int i, int m) {
	if (i == n) return 0;
	ll &ret = dp[i][m];
	if (ret != -1) return ret;
	ret = -1e18;
	ll mx;
	if (cards[i][0].size() >= 3) {
		mx = cards[i][0][0];
		ret = max(ret, (m + 3 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][0][1] + cards[i][0][2] + solve(i + 1, (m + 3) % 10));
	}
	if (cards[i][0].size() >= 2) {
		mx = cards[i][0][0];
		ret = max(ret, (m + 2 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][0][1] + solve(i + 1, (m + 2) % 10));
	}
	if (cards[i][0].size() >= 1) {
		mx = cards[i][0][0];
		ret = max(ret, (m + 1 >= 10 ? mx : 0) + cards[i][0][0] + solve(i + 1, (m + 1) % 10));
	}
	if (cards[i][0].size() >= 1 && cards[i][1].size() >= 1) {
		mx = max(cards[i][0][0], cards[i][1][0]);
		ret = max(ret, (m + 2 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][1][0] + solve(i + 1, (m + 2) % 10));
	}
	if (cards[i][1].size() >= 1) {
		mx = cards[i][1][0];
		ret = max(ret, (m + 1 >= 10 ? mx : 0) + cards[i][1][0] + solve(i + 1, (m + 1) % 10));
	}

	if (cards[i][2].size() >= 1) {
		mx = cards[i][2][0];
		ret = max(ret, (m + 1 >= 10 ? mx : 0) + cards[i][2][0] + solve(i + 1, (m + 1) % 10));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		int k;
		scanf("%d", &k);
		ll a, c;
		loop(j, 0, k - 1) {
			scanf("%lld%lld", &c, &a);
			cards[i][c - 1].push_back(a);
		}
		loop(j, 0, 2) {
			sort(cards[i][j].begin(), cards[i][j].end());
			reverse(cards[i][j].begin(), cards[i][j].end());
		}
	}
	ll OO = -1e18;
	loop(i, 1, n) {
		loop(m, 0, 9) {
			dp[i][m] = OO;
		}
	}
	loop(m, 1, 9) {
		dp[0][m] = OO;
	}
	loop(i, 0, n - 1) {
		loop(m, 0, 9) {
			if (dp[i][m] == OO) continue;
			ll mx;
			if (cards[i][0].size() >= 3) {
				mx = cards[i][0][0];
				dp[i + 1][(m + 3) % 10] = max(dp[i + 1][(m + 3) % 10],dp[i][m] + (m + 3 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][0][1] + cards[i][0][2]);
			}
			if (cards[i][0].size() >= 2) {
				mx = cards[i][0][0];
				dp[i + 1][(m + 2) % 10] = max(dp[i + 1][(m + 2) % 10], dp[i][m] + (m + 2 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][0][1]);
			}
			if (cards[i][0].size() >= 1) {
				mx = cards[i][0][0];
				dp[i + 1][(m + 1) % 10] = max(dp[i + 1][(m + 1) % 10], dp[i][m] + (m + 1 >= 10 ? mx : 0) + cards[i][0][0]);
			}
			if (cards[i][0].size() >= 1 && cards[i][1].size() >= 1) {
				mx = max(cards[i][0][0], cards[i][1][0]);
				dp[i + 1][(m + 2) % 10] = max(dp[i + 1][(m + 2) % 10],dp[i][m] + (m + 2 >= 10 ? mx : 0) + cards[i][0][0] + cards[i][1][0]);
			}
			if (cards[i][1].size() >= 1) {
				mx = cards[i][1][0];
				dp[i + 1][(m + 1) % 10] = max(dp[i + 1][(m + 1) % 10], dp[i][m] + (m + 1 >= 10 ? mx : 0) + cards[i][1][0]);
			}

			if (cards[i][2].size() >= 1) {
				mx = cards[i][2][0];
				dp[i + 1][(m + 1) % 10] = max(dp[i + 1][(m + 1) % 10],dp[i][m] + (m + 1 >= 10 ? mx : 0) + cards[i][2][0]);
			}
			dp[i + 1][m] = max(dp[i + 1][m], dp[i][m]);
		}
	}
	ll ans = -1e18;
	loop(j, 0, 9)
		ans = max(ans, dp[n][j]);
	cout << ans;
}