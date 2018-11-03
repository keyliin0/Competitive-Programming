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

int n, k;
ll g[305][305];

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1)
		loop(j, 0, n - 1)
		scanf("%lld", &g[i][j]);
	scanf("%d", &k);
	while (k--) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		a--;
		b--;
		g[a][b] = min(g[a][b], c);
		swap(a, b);
		g[a][b] = min(g[a][b], c);
		loop(i, 0, n - 1) {
			loop(j, 0, n - 1) {
				g[i][j] = min({ g[i][j],g[i][a] + g[a][j],g[i][b] + g[b][j] });
				g[j][i] = min({ g[j][i],g[j][a] + g[a][i],g[j][b] + g[b][i] });
			}
		}
		ll ans = 0;
		loop(i, 0, n - 1)
			loop(j, i + 1, n - 1)
			ans += g[i][j];
		printf("%lld ", ans);
	}
}