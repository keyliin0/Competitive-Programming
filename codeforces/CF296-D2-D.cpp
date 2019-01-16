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

int n;
ll adj[505][505];
int t[505];
bool f[505];

int main() {
	scanf("%d",&n);
	loop(i, 1, n)
		loop(j, 1, n)
			scanf("%d",&adj[i][j]);
	loop(i, 1, n)
		scanf("%d",&t[i]);
	vector<ll> ans;
	for (int k = n; k >= 1; k--) {
		f[t[k]] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][t[k]] + adj[t[k]][j]);
			}
		ll cost = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (!f[i] || !f[j] || i == j) continue;
				cost += adj[i][j];
			}
		ans.push_back(cost);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%lld ",ans[i]);
}