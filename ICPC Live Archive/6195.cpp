/*
	use topological sort
	if there exist a node that is not visited then there is no arrangement
	if there is more than one node in the queue at the same time than there exist multiple arrangements
	otherwise there exist only one arrangement
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

int n, m;
vector<vector<int> > g;
bool vis[1005];
int in[1005];

int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) return 0;
		g.clear();
		g.resize(n + 1);
		memset(in, 0, sizeof in);
		memset(vis, 0, sizeof vis);
		loop(i, 0, m - 1) {
			int  a, b;
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
			in[b]++;
		}
		queue<int> q;
		loop(i, 1, n)
			if (in[i] == 0) q.push(i);
		int ans = 1;
		while (!q.empty() && ans) {
			if (q.size() > 1) ans = 2;
			int u = q.front();
			q.pop();
			vis[u] = 1;
			for (int i = 0; i < g[u].size(); i++) {
				in[g[u][i]]--;
				if (in[g[u][i]] == 0) q.push(g[u][i]);
			}
		}
		loop(i, 1, n)
			if (!vis[i])
				ans = 0;
		printf("%d\n",ans);
	}
}