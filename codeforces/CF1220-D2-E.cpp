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

int n, m, s;
vector<vector<int> > g;
ll w[N];
bool vis[N], cyc[N];

int dfs1(int u,int p) {
	if (vis[u]) {
		cyc[u] = 1;
		return 1;
	}
	vis[u] = 1;
	int f = 0;
	for (auto v : g[u]) {
		if(v != p)
			f |= dfs1(v, u);
	}
	if (f) cyc[u] = 1;
	return f;
}

ll dfs2(int u) {
	vis[u] = 1;
	ll ret = 0;
	for (auto v : g[u]) {
		if (!vis[v])
			ret = max(ret, (cyc[v] ? 0 : w[v]) + dfs2(v));
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	g.resize(n + 1);
	loop(i, 1, n)
		scanf("%lld",&w[i]);
	loop(i, 0, m - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
	}
	scanf("%d", &s);
	cyc[s] = 1;
	dfs1(s, -1);
	memset(vis, 0, sizeof vis);
	ll ans = dfs2(s);
	loop(i, 1, n)
		if (cyc[i])
			ans += w[i];
	printf("%lld",ans);
}