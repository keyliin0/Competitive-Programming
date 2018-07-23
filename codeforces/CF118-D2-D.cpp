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

int n1, n2, k1, k2, MOD = 1e8;
int dp[101][101][3][11];


int solve(int i1,int i2,int last,int cnt) {
	if (cnt > k1 && last == 1) return 0; // if there is more than k1 consecutive footmen then this is an invalid case
	if (cnt > k2 && last == 2) return 0;// if there is more than k2 consecutive horsemen then this is an invalid case
	if (i1 == 0 && i2 == 0) return 1;
	int &ret = dp[i1][i2][last][cnt];
	if (ret != -1) return ret;
	ret = 0;
	if (i1 > 0) ret = (ret + solve(i1 - 1, i2, 1, (last == 1 ? cnt + 1 : 1))) % MOD; // try to put a horse footmen
	if (i2 > 0) ret = (ret + solve(i1, i2 - 1, 2, (last == 2 ? cnt + 1 : 1))) % MOD; // try to put a horse horsemen
	return ret;
}

int main() {
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, -1, sizeof dp);
	cout << solve(n1, n2, 0, 0);
}
