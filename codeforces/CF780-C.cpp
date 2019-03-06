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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
vector<vector<int> > g;
int ans[N];
int k;

void dfs(int u, int p) {
	int c = 1;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] != p) {
			while (ans[u] == c || ans[p] == c) c++;
			ans[g[u][i]] = c++;
			dfs(g[u][i], u);
		}
	}
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
		k = max({ k,(int)g[a].size() + 1, (int)g[b].size() + 1 });
	}
	ans[1] = 1;
	dfs(1, 0);
	printf("%d\n", k);
	loop(i, 1, n)
		printf("%d ",ans[i]);
}