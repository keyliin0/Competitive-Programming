/*
	recurrence :
	if n == 0 , result = 0 (there is no permutation)
	if k == 0 , result = 1 (the permutation with k = 0 is the current permutation in increasing order)
	else result = f(n - 1,k - i) i < n && k - i >= n
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

int n, k;
int dp[1005][100];

int solve(int n,int k) {
	if (n == 0) return 0;
	if (k == 0) return 1;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n && k - i >= 0; i++)
		ret += solve(n - 1, k - i);
	return ret;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&k);
		memset(dp, -1, sizeof dp);
		int ans = solve(n, k);
		printf("%d\n",ans);
	}
}