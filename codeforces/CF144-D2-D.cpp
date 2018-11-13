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

int n, m, s, l;
int d[N];
vector<vector<pair<int, int> > > g;

int main() {
	scanf("%d%d%d", &n, &m, &s);
	g.resize(n + 1);
	loop(i, 1, n)
		d[i] = oo;
	loop(i, 1, m) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back({ b,c });
		swap(a, b);
		g[a].push_back({ b,c });
	}
	scanf("%d",&l);
	priority_queue<pair<int, int> > q;
	d[s] = 0;
	q.push({ 0,s });
	while (!q.empty()) {
		int u = q.top().second;
		int c = -q.top().first;
		q.pop();
		if (c > d[u]) continue;
		for (int i = 0; i < g[u].size(); i++) {
			if (d[g[u][i].first] > c + g[u][i].second) {
				d[g[u][i].first] = c + g[u][i].second;
				q.push({ -d[g[u][i].first] , g[u][i].first });
			}
		}
	}
	int ans = 0;
	loop(u, 1, n) {
		if (d[u] == l) ans++;
		for (int i = 0; i < g[u].size(); i++) {
			if (u > g[u][i].first) continue;
			int need = l - d[u];
			if (g[u][i].second > need && need > 0 && d[g[u][i].first] + g[u][i].second - need >= l) ans++;
			int need2 = l - d[g[u][i].first];
			if (g[u][i].second > need2 && need2 > 0 && d[u] + g[u][i].second - need2 >= l && g[u][i].second - need2 != need) ans++;
		}
	}
	printf("%d",ans);
}