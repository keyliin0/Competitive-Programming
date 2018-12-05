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

int n, k, m;

struct node{
	int to, c, w;
	node(int to,int w,int c) {
		this->to = to;
		this->w = w;
		this->c = c;
	}
};

vector<vector<node> > g;
int dp[102][10005];

int solve(int u, int t) {
	if (t > k) return oo;
	if (u == n) return 0;
	int &ret = dp[u][t];
	if (ret != -1) return ret;
	ret = oo;
	for (int i = 0; i < g[u].size(); i++) {
		ret = min(ret, g[u][i].w + solve(g[u][i].to, t + g[u][i].c));
	}
	return ret;
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d%d", &k, &n, &m);
		g.clear();
		g.resize(n + 1);
		loop(i, 0, m - 1) {
			int a, b, w, c;
			scanf("%d%d%d%d", &a, &b, &w, &c);
			g[a].push_back(node(b, w, c));
		}
		memset(dp, -1, sizeof dp);
		int ans = solve(1, 0);
		printf("%d\n", (ans == oo ? -1 : ans));
	}
}