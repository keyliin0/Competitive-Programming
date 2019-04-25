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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, w;
int W[1005], B[1005];
vector<vector<int> > g, cmp;

bool vis[1005];
int curr;
void dfs(int u){
	cmp[curr].push_back(u);
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

int dp[1005][1005];
int solve(int i,int rem) {
	if (rem < 0) return -oo;
	if (i == n) return 0;
	int &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = -oo;
	int totalw = 0, totalb = 0;
	for (int j = 0; j < cmp[i].size(); j++) {
		totalw += W[cmp[i][j]];
		totalb += B[cmp[i][j]];
		ret = max(ret, B[cmp[i][j]] + solve(i + 1, rem - W[cmp[i][j]]));
	}
	ret = max(ret, totalb + solve(i + 1, rem - totalw));
	ret = max(ret, solve(i + 1, rem));
	return ret;
}

int main() {
	scanf("%d%d%d",&n,&m,&w);
	cmp.resize(n + 1);
	g.resize(n + 1);
	loop(i, 1, n)
		scanf("%d", &W[i]);
	loop(i, 1, n)
		scanf("%d", &B[i]);
	loop(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	loop(i, 1, n) {
		if (!vis[i]) dfs(i),curr++;
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(0, w);
	printf("%d",max(ans,0));
}