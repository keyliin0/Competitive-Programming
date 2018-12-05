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

vector<vector<int> > g;
int n, k;
ll cst[N];

int main() {
	scanf("%d%d", &k, &n);
	g.resize(k + 1);
	loop(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	priority_queue<pair<ll, int> > q;
	q.push({ 0,1 });
	ll ans = oo;
	loop(i, 1, k)
		cst[i] = oo;
	cst[1] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		ll c = -q.top().first;
		if (u == k) ans = min(ans, c);
		q.pop();
		if (cst[u] < c) continue;
		for (int i = 0; i < g[u].size(); i++) {
			ll d = abs(g[u][i] - u);
			bool up = 1;
			if ((c / d) % 2 != 0) up = 0;
			ll curr = c % d;
			ll cost = c + d;
			if (u < g[u][i]) {
				if (up) {
					if (curr != 0) cost += d + d - curr;
				}
				else {
					cost += d - curr;
				}
			}
			else {
				if (up) {
					cost += d - curr;
				}
				else {
					if (curr != 0) cost += d + d - curr;
				}
			}
			if (cost < cst[g[u][i]]) {
				cst[g[u][i]] = cost;
				q.push({ -cst[g[u][i]],g[u][i] });
			}
		}
	}
	printf("%lld",ans * 5);
}