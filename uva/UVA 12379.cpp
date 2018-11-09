/*
	observation : the given graph is a tree
	to get the optimal answer all edges will be visited twice except the longest path 
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
vector<vector<int> > g;
int mx, curr;

void dfs(int u,int p,int depth) {
	if (depth > mx) {
		mx = depth;
		curr = u;
	}
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] != p) {
			dfs(g[u][i], u, depth + 1);
		}
	}
}


int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		g.clear();
		g.resize(n + 1);
		loop(i, 1, n) {
			int k;
			scanf("%d",&k);
			loop(j, 1, k) {
				int a;
				scanf("%d",&a);
				g[i].push_back(a);
			}
		}
		mx = 0, curr = 1;
		dfs(1, -1, 0);
		dfs(curr, -1, 0);
		printf("%d\n",2 * (n - 1) - mx);
	}
}