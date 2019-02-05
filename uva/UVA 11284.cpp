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
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, p;
double cost[55][55];
double dp[1 << 12][55];
pair<int, double> t[55];
double V[55];

// find shortest path like TSP
double solve(int mask,int u) {
	double &ret = dp[mask][u];
	if (ret == ret) return ret;
	ret = -cost[u][0];
	for (int i = 0; i < p; i++) {
		if (mask & (1 << i)) continue;
			ret = max(ret, solve(mask | (1 << i), t[i].first) - cost[u][t[i].first]);
	}
	ret += V[u]; //add the amount he will save 
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		loop(i, 0, n) {
			loop(j, 0, n)
				cost[i][j] = 1e9;
			cost[i][i] = 0;
		}
		loop(i, 0, m - 1) {
			int a, b;
			double c;
			scanf("%d%d%lf", &a, &b, &c);
			cost[a][b] = min(cost[a][b], c);
			swap(a, b);
			cost[a][b] = min(cost[a][b], c);
		}
		scanf("%d", &p);
		double all = 0;
		memset(V, 0, sizeof V);
		loop(i, 0, p - 1) {
			scanf("%d%lf", &t[i].first, &t[i].second);
			all += t[i].second;
			V[t[i].first] = t[i].second;
		}
		loop(k, 0, n)
			loop(i, 0, n)
				loop(j, 0, n)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		memset(dp, -1, sizeof dp);
		double ans = solve(0, 0);
		if (ans < EPS) printf("Don\'t leave the house\n");
		else printf("Daniel can save $%.2lf\n",ans);
	}
}