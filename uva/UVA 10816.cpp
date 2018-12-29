/*
	(the problem is simpler if there are no multiple edges between pair of nodes)
	build a graph with no multiple edges and keep the edge that has the min temp between pair of nodes
	use floyd to find the min temperature
	iterate again on the edges and keep the edges with temp <= min temp
	if there are multiple choices choose the edge with min length ( since its temp <= min temp it can't make the answer worse )
	now use floyd to find the distance
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

double min_temp[105][105];
int n, m, s, d;
double adj[105][105];
int pre[105][105];

struct edge{
	int a, b;
	double tmp, dist;
	edge(int a, int b, double tmp, double dist) {
		this->a = a;
		this->b = b;
		this->tmp = tmp;
		this->dist = dist;
	}
};

void prt(int i, int j) {
	if (i == j) return;
	prt(i, pre[i][j]);
	printf(" %d", j);
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		scanf("%d%d", &s, &d);
		loop(i, 1, n) {
			loop(j, 1, n) {
				pre[i][j] = i;
				adj[i][j] = 1e15;
				min_temp[i][j] = 1e15;
			}
		}
		vector<edge> edges;
		loop(i, 0, m - 1) {
			int a, b;
			double tmp, dist;
			scanf("%d%d%lf%lf", &a, &b, &tmp, &dist);
			edges.push_back(edge(a, b, tmp, dist));
			min_temp[a][b] = min(min_temp[a][b], tmp);
			min_temp[b][a] = min(min_temp[b][a], tmp);
		}
		loop(k, 1, n)
			loop(i, 1, n)
				loop(j, 1, n)
					min_temp[i][j] = min(min_temp[i][j], max(min_temp[i][k], min_temp[k][j]));
		for (int i = 0; i < edges.size(); i++)
			if (edges[i].tmp <= min_temp[s][d]) {
				adj[edges[i].a][edges[i].b] = min(adj[edges[i].a][edges[i].b], edges[i].dist);
				adj[edges[i].b][edges[i].a] = min(adj[edges[i].b][edges[i].a], edges[i].dist);
			}
		loop(k, 1, n)
			loop(i, 1, n)
				loop(j, 1, n)
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						pre[i][j] = pre[k][j];
					}
		printf("%d",s);
		prt(s, d);
		printf("\n%.1lf %.1lf\n",adj[s][d],min_temp[s][d]);
	}
}