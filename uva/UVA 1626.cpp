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
int dp[105][105];
bool f[105];

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = oo;
	if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']')
		ret = min(ret, solve(l + 1, r - 1));
	for (int i = l; i < r; i++) {
		ret = min(ret, solve(l, i) + solve(i + 1, r));
	}
	return ret;
}

void build(int l, int r) {
	if (l > r) return;
	if (l == r) {
		f[l] = 1;
		return;
	}
	for (int i = l; i < r; i++) {
		if (solve(l, r) == solve(l, i) + solve(i + 1, r)) {
			build(l, i);
			build(i + 1, r);
			return;
		}
	}
	build(l + 1, r - 1);
}

int main() {
	io;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		memset(dp, -1, sizeof dp);
		memset(f, 0, sizeof f);
		solve(0, s.size() - 1);
		build(0, s.size() - 1);
		for (int i = 0; i < s.size(); i++) {
			if (f[i]) {
				if (s[i] == '(' || s[i] == ')') {
					cout << "()";
				}
				else cout << "[]";
			}
			else cout << s[i];
		}
		cout << "\n";
		if (t) cout << "\n";
	}
}