/*
	the problem is similar to traveling salesman problem which can be solved in (2^n) * (n^2) using DP
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

pair<int,int> t[15];
int n, x, y;
int dp[1 << 12][15];

int dist(int x,int xx,int y,int yy) {
	return abs(x - xx) + abs(y - yy);
}

int solve(int mask, int prev) {
	if (mask == (1 << (n + 1)) - 1) {
		return dist(t[prev].first, t[0].first, t[prev].second, t[0].second);
	}
	int &ret = dp[mask][prev];
	if (ret != -1) return ret;
	ret = oo;
	for (int i = 1; i <= n; i++) {
		if (mask & (1 << i)) continue;
		ret = min(ret, dist(t[prev].first, t[i].first, t[prev].second, t[i].second) + solve(mask | (1 << i), i));
	}
	return ret;
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d", &x, &y);
		scanf("%d%d", &t[0].first, &t[0].second);
		scanf("%d",&n);
		loop(i, 1, n)
			scanf("%d%d",&t[i].first,&t[i].second);
		memset(dp, -1, sizeof dp);
		int ans = solve((1 << 0), 0);
		printf("The shortest path has length %d\n",ans);
	}
}