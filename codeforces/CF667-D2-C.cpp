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
set<string> st;
int dp[10006][3];

int solve(int i,int last,string t) {
	if (i == s.size()) return 1;
	if (s.size() - i < 2) return 0;
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = 0;
	string tmp = "";
	loop(j, i, i + 1)
		tmp += s[j];
	if(tmp != t)
		ret |= solve(i + 2, 0, tmp);
	if (ret) st.insert(tmp);
	if (s.size() - i >= 3) {
		tmp += s[i + 2];
		if(tmp != t)
			ret |= solve(i + 3, 1, tmp);
		if (solve(i + 3, 1, tmp)) st.insert(tmp);
	}
	return ret;
}

int main() {
	cin >> s;
	memset(dp, -1, sizeof dp);
	loop(i, 5, s.size() - 1) {
		solve(i, 2, "");
	}
	cout << st.size() << endl;
	for (auto it : st) {
		cout << it << endl;
	}
}