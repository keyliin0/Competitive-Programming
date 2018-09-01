/*
	topological sort
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
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
int in[N];
vector<vector<int> > g;

int main() {
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		memset(in, 0, sizeof in);
		g.clear();
		g.resize(n + 1);
		loop(i, 0, m - 1) {
			int a, b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			in[b]++;
		}
		vector<int> ans;
		queue<int> q;
		loop(i, 1, n)
			if (in[i] == 0) q.push(i);
		while (!q.empty()) {
			int u = q.front();
			ans.push_back(u);
			q.pop();
			for (int i = 0; i < g[u].size(); i++) {
				in[g[u][i]]--;
				if (in[g[u][i]] == 0) q.push(g[u][i]);
			}
		}
		if (ans.size() != n) printf("IMPOSSIBLE\n");
		else {
			for (int i = 0; i < ans.size(); i++)
				printf("%d\n",ans[i]);
		}
	}
}