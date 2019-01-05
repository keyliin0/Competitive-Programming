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
int k;
int dp[1000][1000];
string aa = "";

int solve(int i, int len) {
	if (i == s.size()) return len == k;
	int &ret = dp[i][len];
	if (ret != -1) return ret;
	ret = 0;
	if (s[i] == '*') {
		ret |= solve(i + 1, len - 1);
		ret |= solve(i + 1, len);
		if (ret) return ret;
		for (int j = 1; j + len <= k; j++) {
			ret = solve(i + 1, len + j);
			if (ret) return ret;
		}
	}
	else if (s[i] == '?') {
		ret |= solve(i + 1, len - 1);
		ret |= solve(i + 1, len);
	}
	else ret = solve(i + 1, len + 1);
	return ret;
}

void build(int i, int len) {
	if (i == s.size()) return;
	if (s[i] == '*') {
		if (solve(i, len) == solve(i + 1, len - 1)) {
			aa.pop_back();
			build(i + 1, len - 1);
			return;
		}
		if (solve(i, len) == solve(i + 1, len)) {
			build(i + 1, len);
			return;
		}
		for (int j = 1; j + len <= k; j++) {
			aa += s[i - 1];
			if (solve(i, len) == solve(i + 1, len + j)) {
				build(i + 1, len + j);
				return;
			}
		}
	}
	else if (s[i] == '?') {
		if (solve(i, len) == solve(i + 1, len - 1)) {
			aa.pop_back();
			build(i + 1, len - 1);
			return;
		}
		if (solve(i, len) == solve(i + 1, len)) {
			build(i + 1, len);
			return;
		}
	}
	else if (solve(i, len) == solve(i + 1, len + 1)) {
		aa += s[i];
		build(i + 1, len + 1);
		return;
	}
}

int main() {
	io;
	cin >> s >> k;
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	if (!ans) {
		cout << "Impossible";
		return 0;
	}
	build(0, 0);
	cout << aa;
}