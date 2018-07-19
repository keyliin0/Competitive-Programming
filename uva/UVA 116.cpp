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

int n,m;
int g[15][110];
int dp[15][110];

int solve(int i,int j) {
	if (i == n) i = 0;
	if (i == -1) i = n - 1;
	if (j == m) return 0;
	int &ret = dp[i][j];
	if (ret != oo) return ret;
	ret = oo;
	loop(x, -1, 1)
		ret = min(ret, g[i][j] + solve(i + x, j + 1));
	return ret;
}

void build(int i,int j) {
	if (i == n) i = 0;
	if (i == -1) i = n - 1;
	if (j == m) return;
	int t[3];
	int k = 0;
	loop(x, -1, 1) {
		t[k] = i + x;
		if (t[k] == n) t[k] = 0;
		if (t[k] == -1) t[k] = n - 1;
		k++;
	}
	sort(t, t + k); // we try the smallest index first to make sure we are printing the lexicographically smallest path in case of an equality
	loop(x, 0, 2)
		if (solve(i, j) == g[i][j] + solve(t[x], j + 1)) {
			printf("%d",i + 1);
			if (j != m - 1) printf(" ");
			build(t[x], j + 1);
			return;
		}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		loop(i, 0, n - 1)
			loop(j, 0, m - 1) {
				cin >> g[i][j];
				dp[i][j] = oo;
		}
		int ans = oo, r;
		loop(i, 0, n - 1) {
			if (solve(i, 0) < ans) {
				ans = solve(i, 0);
				r = i;
			}
		}
		build(r, 0);
		printf("\n%d\n",ans);
	}
}
