/*
	we can look consider the problem as a dp consecutive ranges style problem
	we try to split the array to K ranges and check the min answer
	we can precalculate the distance for all ranges so we can use them later
	we know that for a range that starts at L and ends at R , we must build a depot in index (L + R) / 2
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

int n, k;
int t[N];
int dp[205][33];
int cost[205][205];

int calc(int l,int r) {
	int d = 0, m = (l + r) / 2;
	loop(i, l, r)
		d += abs(t[m] - t[i]);
	return d;
}

int solve(int l,int rem) {
	if (l >= n) return 0;
	if (rem <= 0) return oo;
	int &ret = dp[l][rem];
	if (ret != -1) return ret;
	ret = oo;
	for (int i = l; i < n; i++)
		ret = min(ret, cost[l][i] + solve(i + 1, rem - 1));
	return ret;
}

void build(int l,int rem) {
	if (l >= n || rem <= 0) return;
	for (int i = l; i < n; i++) {
		if (solve(l, rem) == cost[l][i] + solve(i + 1, rem - 1)) {
			printf("Depot %d at restaurant %d serves", k - rem + 1, ((l + i) / 2) + 1);
			if (l != i) printf(" restaurants %d to %d", l + 1,i + 1);
			else printf(" restaurant %d", l + 1);
			printf("\n");
			build(i + 1, rem - 1);
			return;
		}
	}
}

int main() {
	int test = 0;
	while (1) {
		test++;
		scanf("%d%d", &n, &k);
		if (n == 0 && k == 0) return 0;
		loop(i, 0, n - 1)
			scanf("%d", &t[i]);
		loop(i, 0, n - 1)
			loop(j, i, n - 1)
			cost[i][j] = calc(i, j);
		memset(dp, -1, sizeof dp);
		int ans = solve(0, k);
		printf("Chain %d\n",test);
		build(0, k);
		printf("Total distance sum = %d\n\n",ans);
	}
}
