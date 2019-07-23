/*
	all nodes must be visited at most k times 
*/
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

int n, m;
vector<vector<pair<int,ll> > > g;
ll cost[55][555]; // [number of times that we visited current node] [number of the current node]
int x, y, k;
int vis[555];

int main() {
	while (scanf("%d%d", &n, &m)) {
		scanf("%d%d%d", &x, &y, &k);
		g.clear();
		g.resize(n + 1);
		if (n == 0) return 0;
		loop(i, 1, m) {
			int a, b;
			ll c;
			scanf("%d%d%lld", &a, &b, &c);
			g[a].push_back({ b,c });
		}
		priority_queue<pair<ll, int> > q;
		ll OO = 1e18;
		loop(i, 1, n)
			loop(j, 1, k)
				cost[j][i] = OO;
		q.push({ 0,x });
		memset(vis, 0, sizeof vis);
		while (!q.empty()) {
			int u = q.top().second;
			ll c = -q.top().first;
			q.pop();
			if (vis[u] >= k) continue;
			vis[u]++;
			cost[vis[u]][u] = c;
			for (auto it : g[u]) {
				q.push({ -(c + it.second) , it.first });
			}
		}
		printf("%lld\n",cost[k][y] == OO ? -1 : cost[k][y]);
	}
}