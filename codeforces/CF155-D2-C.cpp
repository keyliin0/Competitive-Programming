/*
	we can find the longest subsequence where there condition holds
	and the ans will be length of the string - length of the sequence
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

int n;
string s;
bool f[30][30];
int dp[100005][30];

int solve(int i,char last) {
	if (i == s.size()) return 0;
	int &ret = dp[i][last - 'a'];
	if (ret != -1) return ret;
	ret = -oo;
	if (!f[last - 'a'][s[i] - 'a'])
		ret = max(ret, 1 + solve(i + 1, s[i]));
	ret = max(ret, solve(i + 1, last));
	return ret;
}

int main() {
	io;
	cin >> s >> n;
	memset(dp, -1, sizeof dp);
	loop(i, 0, n - 1) {
		char c1, c2;
		cin >> c1 >> c2;
		f[c1 - 'a'][c2 - 'a'] = f[c2 - 'a'][c1 - 'a'] = 1;
	}
	cout << (int)s.size() - solve(0, 'z' + 1);
}