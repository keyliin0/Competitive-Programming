/*
	run floyd to get shortest path between all pairs of nodes
	print the path
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

int n;
int adj[15][15],path[15][15];

void build(int from,int to) {
	if (path[from][to] == -1) {
		printf("%d ",from);
		return;
	}
	build(from, path[from][to]);
	build(path[from][to],to);
}

int main() {
	int tt = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		tt++;
		printf("Case %d: Path = ", tt);
		loop(i, 1, n)
			loop(j, 1, n)
			adj[i][j] = oo, path[i][j] = -1;
		loop(i, 1, n) {
			int m;
			scanf("%d", &m);
			loop(j, 1, m) {
				int a, b;
				scanf("%d%d", &a, &b);
				adj[i][a] = b;
			}
		}
		int from, to;
		scanf("%d%d", &from, &to);
		loop(k, 1, n) {
			loop(i, 1, n) {
				loop(j, 1, n) {
					if (adj[i][k] < oo && adj[k][j] < oo && adj[i][k] + adj[k][j] < adj[i][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						path[i][j] = k;
					}
				}
			}
		}
		build(from, to);
		printf("%d; %d second delay\n", to, adj[from][to]);
	}
}