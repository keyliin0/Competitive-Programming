/*
	classic dp style problem
	hardest part is to build the output
	so I mem not only the length of the subsequence but also the string so i can choose
	the lexicographically smallest one
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

string s;
pair<int,string> dp[1001][1001];

pair<int, string> calc(int i, int j) {
	if (i == j) {
		string r = "";
		r += s[i];
		return {1,r};
	}
	if (i > j) return {0,""};
	pair<int,string> &ret = dp[i][j];
	if (ret.first != -1) return ret;
	if (s[i] == s[j]) {
		pair<int, string > choice = calc(i + 1, j - 1);
		ret = { choice.first + 2, s[i] + choice.second };
	}
	else {
		pair<int, string > choice1 = calc(i, j - 1);
		pair<int, string > choice2 = calc(i + 1, j);
		if (choice1.first == choice2.first) {
			if (choice1.second > choice2.second) ret = choice2;
			else ret = choice1;
		}
		else if (choice1.first > choice2.first) ret = choice1;
		else ret = choice2;
	}
	return ret;
}

int main() {
	io;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++)
			for (int j = 0; j < s.size(); j++)
				dp[i][j].first = -1;
		pair<int, string> ans = calc(0, s.size() - 1);
		cout << ans.second;
		reverse(ans.second.begin(), ans.second.end());
		for (int i =(ans.first & 1); i < ans.second.size(); i++)
			cout << ans.second[i];
		cout << endl;
	}
}
