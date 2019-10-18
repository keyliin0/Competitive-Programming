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


int dp[105][200005];
int n;
int A[N], B[N];
int k;
int off = 1e5;

int solve(int i,int sum) {
	if (i == n) {
		return sum == off ? 0 : -oo;
	}
	if (dp[i][sum] != -1) return dp[i][sum];
	int ret = -oo;
	ret = max(ret, A[i] + solve(i + 1, sum + A[i] - k * B[i]));
	ret = max(ret, solve(i + 1, sum));
	return dp[i][sum] = ret;
}

int main() {
	scanf("%d%d", &n, &k);
	loop(i, 0, n - 1)
		scanf("%d", &A[i]);
	loop(i, 0, n - 1)
		scanf("%d", &B[i]);
	memset(dp, -1, sizeof dp);
	int ans = solve(0, off);
	if (ans == 0) printf("-1");
	else printf("%d",ans);
}
 