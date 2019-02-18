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

int t[3][3005];
int dp[3005][3005];
int n;

int calc(int i,int last) {
	int res = t[0][i];
	if (last == 1) res = t[1][last];
	else res = t[2][last];
	for (int j = last + 1; j < i; j++)
		res += t[1][j];
	return res;
}

int solve(int i, int last) {
	if (i == n + 1) {
		if (last != i) return -oo;
		return 0;
	}
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = -oo;
	ret = max(ret, solve(i + 1, last));
	if(last != i) ret = max(ret, t[0][i] + calc(i, last) + solve(i + 1, i + 1));
	else ret = max(ret, (last == 1 ? t[0][i] : t[1][i]) + solve(i + 1, i + 1));
	return ret;
}

int main() {
	scanf("%d", &n);
	loop(j, 0, 2)
		loop(i, 1, n)
		scanf("%d", &t[j][i]);
	memset(dp, -1, sizeof dp);
	t[2][n] = t[2][1] = -oo;
	int ans = solve(1, 1);
	printf("%d", ans);
}