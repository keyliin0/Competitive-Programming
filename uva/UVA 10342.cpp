/*
	find shortest path to all nodes using floyd
	then try to use every edge and check the minimum cost which is greater than the shortest path
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

int n, m;
int mincost[105][105], maxcost[105][105];


int main() {
	int cas = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		loop(i, 0, n - 1)
			loop(j, 0, n - 1) {
			if (i == j) mincost[i][j] = 0;
			else {
				mincost[i][j] = oo;
				maxcost[i][j] = oo;
			}
		}
		vector<pair<pair<int, int>, int> > v;
		loop(i, 0, m - 1) {
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			mincost[a][b] = c;
			mincost[b][a] = c;
			v.push_back({ {a,b},c });
			v.push_back({ {b,a},c });
		}
		loop(k, 0, n - 1)
			loop(i, 0, n - 1)
				loop(j, 0, n - 1)
					mincost[i][j] = min(mincost[i][j], mincost[i][k] + mincost[k][j]);
		loop(i,0,n-1)
			loop(j, 0, n - 1) {
			int mn = oo;
			for (int k = 0; k < v.size(); k++) {
				int c = mincost[i][v[k].first.first] + v[k].second + mincost[v[k].first.second][j];
				if (c > mincost[i][j]) mn = min(mn, c);
			}
			maxcost[i][j] = mn;
		}
		cas++;
		printf("Set #%d\n",cas);
		int q;
		scanf("%d",&q);
		while (q--) {
			int a, b;
			scanf("%d%d",&a,&b);
			if (maxcost[a][b] == oo) printf("?\n");
			else printf("%d\n", maxcost[a][b]);
		}
	}
}