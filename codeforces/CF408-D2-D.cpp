/*
	notice that to get out of the i-th room you need to know the number of portals to get out of the rooms from p[i] to i - 1
	the result will be the their sum + 2 (+2 because you used the second portal of the current room once and then first to get out from it)
*/
#include <bits/stdc++.h>
#include <unordered_map>
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

ll dp[1005];
int n;
int t[1005];

int main() {
	scanf("%d",&n);
	loop(i, 1, n)
		scanf("%d",&t[i]);
	dp[1] = 2;
	loop(i, 2, n) {
		dp[i] = 2;
		loop(j, t[i], i - 1)
			dp[i] = (dp[i] + dp[j]) % mod;
	}
	ll ans = 0;
	loop(i, 1, n)
		ans = (ans + dp[i]) % mod;
	printf("%lld",ans);
}