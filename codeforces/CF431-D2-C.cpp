/*
	each time try to go to every k node and stop when the sum of the edges > n or equal n
	and use memo while calculating the ans
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

ll dp[105][2];
int n, k, d;

ll calc(int sum,bool weight) {
	if (sum == n) return weight;
	if (sum > n) return 0;
	ll &ret = dp[sum][weight];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= k; i++) {
		ret = (ret + calc(sum + i, weight || (i >= d))) % mod;
	}
	return ret;
}

int main() {
	cin >> n >> k >> d;
	memset(dp, -1, sizeof dp);
	cout << calc(0,0) % mod;
}