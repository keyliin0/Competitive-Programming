/*
	that 2 straws are connected if they intersect
	run floyd to find if there is a path between all pairs of straws
	if there is a path between a and b or b and a then they are connected
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

struct pt{
	int x, y;
};

int n;
bool g[15][15];
pair<point, point> t[15];

int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
	// special case handling if a segment is just a point
	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
int main() {
	int tests;
	scanf("%d",&tests);
	int line = 0;
	while (tests--) {
		if (line) printf("\n");
		memset(g, 0, sizeof g);
		scanf("%d",&n);
		loop(i, 0, n - 1) {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
			t[i].first = point(x1, y1);
			t[i].second = point(x2, y2);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (intersect(t[i].first, t[i].second, t[j].first, t[j].second))
					g[i][j] = 1;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] |= (g[i][k] & g[k][j]);
		int a = -1, b = -1;
		while (1) {
			scanf("%d%d",&a,&b);
			if (a == 0 || b == 0) break;
			a--, b--;
			if (g[a][b]) printf("CONNECTED\n");
			else printf("NOT CONNECTED\n");
		}
		line = 1;
	}
}