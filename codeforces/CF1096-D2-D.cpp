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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll dp[N][5];
ll t[N], t2[N];
string s2 = "";
int n;
string s;

ll solve(int i,int last) {
	if (i == s2.size()) return 0;
	ll &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = 1e15;
	if (last == 0 && s2[i] == 'h')
		ret = min(ret, solve(i + 1, 1));
	else if(last == 1 && s2[i] == 'a')
		ret = min(ret, solve(i + 1, 2));
	else if (last == 2 && s2[i] == 'r')
		ret = min(ret, solve(i + 1, 3));
	else if (last == 3 && s2[i] == 'd')
		ret = min(ret, t2[i] + solve(i + 1, 3));
	else ret = min(ret, solve(i + 1, last));
	ret = min(ret, t2[i] + solve(i + 1, last));
	return ret;
}

int main() {
	io;
	cin >> n >> s;
	loop(i, 0, n - 1)
		cin >> t[i];
	char c = '/';
	loop(i, 0, n - 1) {
		if (s[i] == 'h' || s[i] == 'a' || s[i] == 'r' || s[i] == 'd') {
			if (c != s[i]) {
				c = s[i];
				s2 += c;
				
			}
			t2[s2.size() - 1] += t[i];
		}
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 0);
	cout << ans;
}