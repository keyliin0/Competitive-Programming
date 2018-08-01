/*
	run normal floyd to count number of paths
	if a node is a cycle to itself then all nodes connected to it have infinite number of paths
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

int n, m;
int g[105][105];

int main() {
	int test = 0;
	while (scanf("%d", &n) != EOF) {
		m = 0;
		memset(g, 0, sizeof g);
		loop(i, 0, n - 1) {
			int a, b;
			scanf("%d%d",&a,&b);
			g[a][b] = 1;
			m = max(m, max(a, b));
		}
		loop(k, 0, m)
			loop(i, 0, m)
				loop(j, 0, m) {
					g[i][j] += (g[i][k] * g[k][j]);
		}
		loop(k, 0, m) {
			if (g[k][k])
				loop(i, 0, m)
					loop(j, 0, m)
						if(g[i][k] && g[k][j]) g[i][j] = -1;
		}
		printf("matrix for city %d\n",test);
		loop(i, 0, m) {
			loop(j, 0, m) {
				if (j) printf(" ");
				printf("%d", g[i][j]);
			}
			printf("\n");
		}
		test++;
	}
}