/*
	if two circle intersect we can connect them and represent the connected circles as a graphdefaults
	and the number of nodes in the largest connected component will be the answer
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
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

struct cir {
	double x, y, r;
};


int n;
cir t[105];
vector<vector<int> > g;
int cnt;
bool vis[105];

void dfs(int u) {
	vis[u] = 1;
	cnt++;
	for (int i = 0; i < g[u].size(); i++) {
		if (!vis[g[u][i]]) dfs(g[u][i]);
	}
}

int circle_intersect(double x1, double y1, double x2, double y2, double r1, double r2) {
	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 + r2 > d && abs(r1 - r2) <= d) return 1;
	return 0;
}


int main() {
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		loop(i, 0, n - 1)
			scanf("%lf%lf%lf", &t[i].x, &t[i].y, &t[i].r);
		g.clear();
		g.resize(n + 1);
		loop(i, 0, n - 1) {
			loop(j, i + 1, n - 1) {
				if (circle_intersect(t[i].x, t[i].y, t[j].x, t[j].y, t[i].r, t[j].r)) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		memset(vis, 0, sizeof vis);
		int ans = 0;
		loop(i, 0, n - 1) {
			if (!vis[i]) {
				cnt = 0;
				dfs(i);
				ans = max(ans, cnt);
			}
		}
		printf("The largest component contains %d ring", ans);
		if (ans != 1) printf("s");
		printf(".\n");
	}
}
