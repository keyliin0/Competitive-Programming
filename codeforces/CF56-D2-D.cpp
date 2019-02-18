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

string s, t;
int dp[1005][1005];

int solve(int i,int j) {
	if (j == t.size()) return s.size() - i;
	if (i == s.size()) return t.size() - j;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = oo;
	if (s[i] == t[j]) ret = min(ret, solve(i + 1, j + 1));
	ret = min(ret, 1 + solve(i + 1, j));
	ret = min(ret, 1 + solve(i, j + 1));
	ret = min(ret, 1 + solve(i + 1, j + 1));
	return ret;
}

int idx = 1;
void build(int i, int j) {
	if (j == t.size()) {
		for (int k = i; k < s.size(); k++)
			cout << "DELETE " << idx-- << "\n";
		return;
	}
	if (i == s.size()) {
		for (int k = j; k < t.size(); k++)
			cout << "INSERT " << idx++ << " " << t[k] << "\n";
		return;
	}
	if (s[i] == t[j] && solve(i, j) == solve(i + 1, j + 1)) {
		idx++;
		build(i + 1, j + 1);
		return;
	}
	if (solve(i, j) == 1 + solve(i + 1, j)) {
		cout << "DELETE " << idx << "\n";
		build(i + 1, j);
		return;
	}
	if (solve(i, j) == 1 + solve(i, j + 1)) {
		cout << "INSERT " << idx++ << " " << t[j] << "\n";
		build(i, j + 1);
		return;
	}
	if (solve(i, j) == 1 + solve(i + 1, j + 1)) {
		cout << "REPLACE " << idx++ << " " <<  t[j] << "\n";
		build(i + 1, j + 1);
		return;
	}
}

int main() {
	io;
	cin >> s >> t;
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	cout << ans << "\n";
	build(0, 0);
}