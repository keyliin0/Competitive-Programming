#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

string s1, s2;
int dp[205][205][405];

int solve(int i,int j,int rem) {
	if (rem >= 400) return oo;
	if (i == s1.size() - 1 && j == s2.size() - 1) return rem;
	int &ret = dp[i][j][rem];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, 1 + solve(i + (s1[i] == '('), j + (s2[j] == '('), rem + 1));
	if(rem) ret = min(ret, 1 + solve(i + (s1[i] == ')'), j + (s2[j] == ')'), rem - 1));
	return ret;
}

void build(int i,int j,int rem) {
	if (i == s1.size() - 1 && j == s2.size() - 1) {
		while (rem--) cout << ')';
		return;
	}
	if (solve(i, j, rem) == 1 + solve(i + (s1[i] == '('), j + (s2[j] == '('), rem + 1)) {
		cout << '(';
		build(i + (s1[i] == '('), j + (s2[j] == '('), rem + 1);
		return;
	}
	if (rem && solve(i, j, rem) == 1 + solve(i + (s1[i] == ')'), j + (s2[j] == ')'), rem - 1)) {
		cout << ')';
		build(i + (s1[i] == ')'), j + (s2[j] == ')'), rem - 1);
		return;
	}
}

int main() {
	io;
	cin >> s1 >> s2;
	s1 += '/';
	s2 += '/';
	memset(dp, -1, sizeof dp);
	//cout << solve(0, 0, 0);
	build(0, 0, 0);
}