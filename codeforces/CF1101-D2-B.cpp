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

string s;
int dp[500005][6];
char c[] = { '[',':', '|',']' };

int solve(int i, int last) {
	if (i == s.size()) {
		return last == 5 ? 0 : -oo;
	}
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = -oo;
	if (s[i] == '[') {
		if (last == 0) ret = max(ret, 1 + solve(i + 1, 1));
	}
	else if (s[i] == ':') {
		if (last == 1) ret = max(ret, 1 + solve(i + 1, 2));
		if (last == 3 || last == 2) ret = max(ret, 1 + solve(i + 1, 4));
	}
	else if (s[i] == '|') {
		if (last == 2 || last == 3) ret = max(ret, 1 + solve(i + 1, 3));
	}
	else if (s[i] == ']') {
		if (last == 4) ret = max(ret, 1 + solve(i + 1, 5));
	}
	ret = max(ret, solve(i + 1, last));
	return ret;
}

int main() {
	cin >> s;
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	cout << (ans < 0 ? -1 : ans);
}