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
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
int n;
vector<vector<int> > g;
ll in[N], out[N], dp[N];
 
void dfs1(int u,int p) {
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs1(v, u);
		dp[u] += dp[v];
	}
	dp[u]++;
}
 
void dfs2(int u, int p) {
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs2(v, u);
		in[u] += in[v] + dp[v];
	}
}
 
void dfs3(int u, int p) {
	for (auto v : g[u]) {
		if (v == p) continue;
		out[v] += out[u] + in[u] - in[v] - dp[v] + n - dp[v];
		dfs3(v, u);
	}
}
 
 
int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	dfs3(1, -1);
	ll ans = 0;
	loop(i, 1, n) {
		//cout << i << " " << in[i] << "  " << out[i] << "\n";
		ans = max(ans, in[i] + out[i] + n );
	}
	cout << ans;
}