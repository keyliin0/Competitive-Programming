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

int dp[N], t[N];
int n;

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	int ans = 1;
	loop(i, 0, n - 1) {
		if (t[i] == 1) continue;
		int mx = 0;
		for (int j = 2; j * j <= t[i]; j++) {
			if (t[i] % j == 0) {
				mx = max(dp[j], mx);
				if (t[i] / j != j) 
					mx = max(dp[t[i] / j], mx);
			}
		}
		mx = max(dp[t[i]], mx);
		for (int j = 2; j * j <= t[i]; j++) {
			if (t[i] % j == 0) {
				dp[j] = max(dp[j], mx + 1);
				if (t[i] / j != j)
					dp[t[i] / j] = max(dp[t[i] / j], mx + 1);
			}
		}
		dp[t[i]] = max(dp[t[i]], mx + 1);
		ans = max(ans, mx + 1);
	}
	printf("%d",ans);
}