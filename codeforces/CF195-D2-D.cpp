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

string s;
int m;
int f;
ll dp[1 << 18][101];
int freq[10];
ll fact[20];

ll solve(int mask,int mod) {
	if (mask == f) return mod == 0;
	ll &ret = dp[mask][mod];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '0' && mask == 0) || (mask & (1 << i))) continue;
		ret += solve(mask | (1 << i), (mod * 10 + (s[i] - '0')) % m);
	}
	return ret;
}

int main() {
	cin >> s >> m;
	f = (1 << s.size()) - 1;
	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 0);
	for (int i = 0; i < s.size(); i++)
		freq[s[i] - '0']++;
	fact[0] = 1;
	for (int i = 1; i < 20; i++) {
		fact[i] = (ll)fact[i - 1] * i;
	}
	for (int i = 0; i < 10; i++) {
		ans /= fact[freq[i]];
	}
	cout << ans;
}