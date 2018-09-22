/*
	pre process how many caracters you need to change for every range to make it palindrome
	then the problem becomes a classic dp consecutive ranges style
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
int k;
int dp[501][501], dp2[501][501];

int solve2(int i, int rem) {
	if (i == s.size()) return 0;
	if (rem <= 0) return oo;
	int &ret = dp2[i][rem];
	if (ret != -1) return ret;
	ret = oo;
	loop(j, i, s.size() - 1) {
		ret = min(ret, dp[i][j] + solve2(j + 1, rem - 1));
	}
	return ret;
}

int solve1(int i, int j) {
	if (i >= j) return dp[i][j] = 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = (s[i] != s[j]) + solve1(i + 1, j - 1);
	return ret;
}

void build(int i,int rem) {
	if (i == s.size()) return;
	loop(j, i, s.size() - 1) {
		if (solve2(i, rem) == dp[i][j] + solve2(j + 1, rem - 1)) {
			for (int x = i; x <= (i + j) / 2; x++)
				cout << s[x];
			for (int x = (i + j) / 2 - ((j - i + 1) % 2); x >= i; x--)
				cout << s[x];
			if (j + 1 != s.size()) cout << "+";
			build(j + 1, rem - 1);
			return;
		}
	}
}

int main() {
	io;
	cin >> s >> k;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < s.size(); i++)
		for (int j = i; j < s.size(); j++)
			solve1(i, j);
	memset(dp2, -1, sizeof dp2);
	int ans = solve2(0, k);
	cout << ans << endl;
	build(0, k);
}