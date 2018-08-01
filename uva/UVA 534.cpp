/*
	give each point an id and consider it as a node
	then run floyd
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

pair<int, int> t[205];
double adj[205][205];
int n;

int main() {
	int test = 0;
	while(1){
		scanf("%d",&n);
		if (n == 0) break;
		loop(i, 0, n - 1)
			scanf("%d%d",&t[i].first,&t[i].second);
		loop(i, 0, n - 1) {
			loop(j, 0, n - 1) {
				if (i == j) adj[i][j] = -1;
				else adj[i][j] = (double)sqrt((t[i].first - t[j].first) * (t[i].first - t[j].first) + (t[i].second - t[j].second) * (t[i].second - t[j].second));
			}
		}
		loop(k, 0, n - 1) {
			loop(i, 0, n - 1) {
				loop(j, 0, n - 1) {
					if (adj[i][k] != -1 && adj[k][j] != -1)
						adj[i][j] = min(adj[i][j], max(adj[i][k] , adj[k][j]));
				}
			}
		}
		test++;
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",test,adj[0][1]);
	}
}