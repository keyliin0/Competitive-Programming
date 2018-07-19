/*
	if the left and right caracter are equal we dont do anything
	otherwise we try to add a character to the left then to the right
	and take the min
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
int dp[1005][1005];
string output1, output2;

int calc(int i, int j) {
	if (i >= j) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = oo;
	if (s[i] == s[j])
		ret = calc(i + 1, j - 1);
	else {
		ret = min(ret, 1 + calc(i + 1, j));	// add a character to the right
		ret = min(ret, 1 + calc(i, j - 1)); // add a character to the left
	}
	return ret;
}

void build(int i,int j) {
	if (i == j) {
		output1 += s[i];
		return;
	}
	if (i >= j) return;
	if (s[i] == s[j]) {
		output1 += s[i];
		output2 = s[j] + output2;
		build(i + 1, j - 1);
	}
	else {
		if (calc(i, j) == 1 + calc(i + 1, j)) {
			output2 = s[i] + output2;
			output1 += s[i];
			build(i + 1, j);
		}
		else {
			output1 += s[j];
			output2 = s[j] + output2;
			build(i, j - 1);
		}
	}
}

int main() {
	io;
	while (cin >> s) {
		memset(dp, -1, sizeof dp);
		int mn = calc(0, s.size() - 1);
		output1 = output2 = "";
		build(0, s.size() - 1);
		cout << mn << " " << output1 << output2 << endl;
	}
}
