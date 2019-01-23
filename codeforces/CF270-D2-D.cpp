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

int n, m;
int t[N];
int dp[5005][5005];

int solve(int i,int last) {
	if (i == n) return 0;
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = oo;
	if (t[i] >= last) ret = min(ret, solve(i + 1, t[i]));
	ret = min(ret, 1 + solve(i + 1, last));
	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1) {
		double x;
		scanf("%d%lf", &t[i], &x);
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	printf("%d",ans);
}