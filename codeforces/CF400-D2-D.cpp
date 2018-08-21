/*
	first we need to check if all nodes of the same type can reach each other with cost 0
	use disjoint set to build a graph which the weight of all edges = 0 so we only check if all nodes of the same type are in the same component
	use floyd to find shortest path
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

int d[505][505];
int n, m, k;
vector<vector<pair<int, int>> > g;
int t[505];
int type[N];
bool sol = 1;
int p[N];

int find(int u) {
	if (p[u] == u)
		return u;
	return p[u] = find(p[u]);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	g.resize(n + 1);
	loop(i, 0, k - 1) {
		scanf("%d", &t[i]);
		if (i > 0) t[i] += t[i - 1];
		loop(j, (i == 0 ? 1 : t[i - 1] + 1), t[i]) {
			type[j] = i;
		}
	}
	loop(i, 1, n)
		p[i] = i;
	loop(i, 0, k - 1)
		loop(j, 0, k - 1)
			d[i][j] = i == j ? 0 : oo;
	loop(i, 0, m - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
		d[type[a]][type[b]] = d[type[b]][type[a]] = min(d[type[a]][type[b]], c);
		if (c == 0) {
			a = find(a);
			b = find(b);
			if (a != b) p[a] = b;
		}
	}
	loop(i, 0, k - 1) {
		int a = find((i == 0 ? 1 : t[i - 1] + 1));
		loop(j, (i == 0 ? 1 : t[i - 1] + 1) + 1, t[i]) {
			int x = find(j);
			sol &= a == x;
		}
	}
	if (!sol) {
		printf("No");
		return 0;
	}
	loop(f, 0, k - 1)
		loop(i, 0, k - 1)
			loop(j, 0, k - 1)
				d[i][j] = min(d[i][j], d[i][f] + d[f][j]);
	printf("Yes\n");
	loop(i, 0, k - 1) {
		loop(j, 0, k - 1) {
			printf("%d ", d[i][j] == oo ? -1 : d[i][j]);
		}
		printf("\n");
	}
}