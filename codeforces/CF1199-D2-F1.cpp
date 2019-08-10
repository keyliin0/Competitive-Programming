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
 
int n;
vector<string> g;
int sum[55][55];
int dp[55][55][55][55];
 
int sum_range(int i, int j, int k, int l) {
	return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
 
int solve(int x1, int y1, int x2, int y2) {
	if (sum_range(x1, y1, x2, y2) == 0) return 0;
	int &ret = dp[x1][y1][x2][y2];
	if (ret != -1) return ret;
	ret = max(x2 - x1 + 1, y2 - y1 + 1);
	loop(i, x1, x2 - 1)
		ret = min(ret, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
	loop(i, y1, y2 - 1)
		ret = min(ret, solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
	return ret;
}
 
int main() {
	io;
	cin >> n;
	string a = "";
	while (a.size() != n + 1)
		a += '/';
	g.push_back(a);
	loop(i, 0, n - 1) {
		string s;
		cin >> s;
		s = "/" + s;
		g.push_back(s);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = g[i][j] == '#';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] += sum[i][j - 1];
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
			sum[i][j] += sum[i - 1][j];
	memset(dp, -1, sizeof dp);
	cout << solve(1, 1, n, n);
}