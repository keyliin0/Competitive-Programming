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
vector<vector<pair<int,ll> > > g;
double ans, ways;
int parent[N];
ll sz[N];
pair<pair<int,int>,ll> t[N];

int dfs(int u,int p) {
	int ret = 1;
	parent[u] = p;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].first != p) {
			int cnt = dfs(g[u][i].first, u);
			ll m1 = cnt;
			ll m2 = n - cnt;
			ll x = n;
			if (m2 >= 2) ans += 2.0 * g[u][i].second * (m2 * (m2 - 1) / 2) * m1;
			if (m1 >= 2) ans += 2.0 * g[u][i].second * (m1 * (m1 - 1) / 2) * m2;
			ret += cnt;
		}
	}
	return sz[u] = ret;
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(i, 0, n - 2) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		t[i + 1] = { {a,b},c };
		g[a].push_back({ b , c });
		g[b].push_back({ a , c });
	}
	ways = (double) n * (n - 1)*(n - 2) / 6;
	dfs(1, -1);
	int q;
	scanf("%d",&q);
	while (q--) {
		int i;
		ll c;
		scanf("%d%lld",&i,&c);
		int a = t[i].first.first, b = t[i].first.second;
		if (parent[b] != a) swap(a, b);
		ll m1 = sz[b];
		ll m2 = n - sz[b];
		ll x = n;
		if (m2 >= 2) ans -= 2.0 * t[i].second * (m2 * (m2 - 1) / 2) * m1;
		if (m1 >= 2) ans -= 2.0 * t[i].second * (m1 * (m1 - 1) / 2) * m2;
		if (m2 >= 2) ans += 2.0 * c * (m2 * (m2 - 1) / 2) * m1;
		if (m1 >= 2) ans += 2.0 * c * (m1 * (m1 - 1) / 2) * m2;
		t[i].second = c;
		printf("%.9lf\n", ans / ways);
	}
}