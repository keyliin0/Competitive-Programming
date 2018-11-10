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

int n;
pair<int, int> dp[N];
int t[N];

int main() {
	int test;
	int cas = 0;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		loop(i, 0, n - 2) {
			scanf("%d",&t[i]);
		}
		dp[0].first = t[0];
		dp[0].second = 0;
		int mx = dp[0].first, ans1 = 1, ans2 = 2;
		loop(i, 1, n - 2) {
			if (dp[i - 1].first + t[i] >= t[i]) {
				dp[i].first = dp[i - 1].first + t[i];
				dp[i].second = dp[i - 1].second;
				if (dp[i].first > mx) {
					mx = dp[i].first;
					ans1 = dp[i].second + 1;
					ans2 = i + 2;
				}
				else if (dp[i].first == mx) {
					if (i - dp[i].second + 1 > ans2 - ans1) {
						ans1 = dp[i].second + 1;
						ans2 = i + 2;
					}
					if (dp[i].second + 1 == ans1) ans2 = i + 2;
				}
			}
			else {
				dp[i].first = t[i];
				dp[i].second = i;
				if (dp[i].first > mx) {
					mx = dp[i].first;
					ans1 = i + 1;
					ans2 = i + 2;
				}
			}
		}
		if (mx <= 0) printf("Route %d has no nice parts\n",++cas);
		else printf("The nicest part of route %d is between stops %d and %d\n", ++cas, ans1, ans2);
	}
}