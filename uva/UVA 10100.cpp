#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

/*19:45 - 20:00 mem*/

string s1, s2;
vector<string> a, b;

int dp[1005][1005];

bool isletter(char c) {
	if (c >= '0' && c <= '9') return 1;
	if (c - 'A' >= 0 && c - 'A' <= 25) return 1;
	if (c - 'a' >= 0 && c - 'a' <= 25) return 1;
	return 0;
}
// sol with memo
int solve(int i,int j) {
	if (i == a.size() || j == b.size()) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = max(ret, solve(i + 1, j));
	ret = max(ret, solve(i, j + 1));
	if (a[i] == b[j]) ret = max(ret, 1 + solve(i + 1, j + 1));
	return ret;
}

int main() {
	int test = 0;
	while (getline(cin, s1)) {
		memset(dp, 0, sizeof dp);
		a.clear();
		b.clear();
		getline(cin, s2);
		test++;
		if (s1.size() == 0 || s2.size() == 0) {
			printf("%2d. Blank!\n", test);
			continue;
		}
		string tmp = "";
		for (int i = 0; i < s1.size(); i++) {
			if (isletter(s1[i])) tmp += s1[i];
			else {
				if (tmp != "") a.push_back(tmp);
				tmp = "";
			}
		}
		if (tmp != "") a.push_back(tmp);
		tmp = "";
		for (int i = 0; i < s2.size(); i++) {
			if (isletter(s2[i])) tmp += s2[i];
			else {
				if (tmp != "") b.push_back(tmp);
				tmp = "";
			}
		}
		if (tmp != "") b.push_back(tmp);
		// sol with dp
		for(int i = 0; i < a.size();i++)
			for (int j = 0; j < b.size(); j++) {
				dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j + 1]));
				if (a[i] == b[j]) dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
			}
		//int ans = solve(0, 0);
		printf("%2d. Length of longest match: %d\n", test, dp[a.size()][b.size()]);
	}
}