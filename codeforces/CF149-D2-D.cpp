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

int close[N];
string s;
ll dp[705][705][3][3];

ll solve(int l,int r,int cl,int cr) {
	if (l > r || l >= s.size()) return 1;
	ll &ret = dp[l][r][cl][cr];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= 2; i++)
		if (cl != i) {
			ret += ( (solve(l + 1, close[l] - 1, i, 0) % mod) * (solve(close[l] + 1, r, 0, cr) % mod) ) % mod;
			ret %= mod;
		}
	for (int i = 1; i <= 2; i++) {
		if (close[l] != r)
			ret += ((solve(l + 1, close[l] - 1, 0, i) % mod) * (solve(close[l] + 1, r, i, cr) % mod)) % mod;
		else if (cr != i)
			ret += ((solve(l + 1, close[l] - 1, 0, i) % mod) * (solve(close[l] + 1, r, i, cr) % mod)) % mod;
		ret %= mod;
	}
	return ret;
}

int main() {
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(i);
		else {
			int idx = st.top();
			st.pop();
			close[idx] = i;
		}
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(0, s.size() - 1, 0, 0);
	cout << ans;
}