/*
	find min distance between two pairs of polygons
	the min distance is either from a vertex to another or from a vertex to the perpendicular point to an edge
	then use floyd
*/
#include<bits/stdc++.h>
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

double adj[505][505];

point perpendicular_point(double x1, double y1, double x2, double y2, double x3, double y3) {
	double k = ((y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1)) / ((y2 - y1) *(y2 - y1) + (x2 - x1) * (x2 - x1));
	return point(x3 - k * (y2 - y1), y3 + k * (x2 - x1));
}

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

double mindist(vector<point> &p1, vector<point> &p2) {
	double x = 1e18;
	for (int i = 0; i < p1.size() - 1; i++) {
		for (int j = 0; j < p2.size() - 1; j++) {
			point a = p1[i], b = p1[i + 1];
			point c = p2[j], d = p2[j + 1];
			x = min(x, sqrt(norm(a - c)));
			x = min(x, sqrt(norm(a - d)));
			x = min(x, sqrt(norm(b - c)));
			x = min(x, sqrt(norm(b - d)));
			// per distance
			point per1 = perpendicular_point(c.X, c.Y, d.X, d.Y, a.X, a.Y);
			point per2 = perpendicular_point(c.X, c.Y, d.X, d.Y, b.X, b.Y);
			point per3 = perpendicular_point(a.X, a.Y, b.X, b.Y, c.X, c.Y);
			point per4 = perpendicular_point(a.X, a.Y, b.X, b.Y, d.X, d.Y);
			if (ccw(c, d, per1) == 0) x = min(x, sqrt(norm(a - per1))); // ccw to check if the per point is on the segment
			if (ccw(c, d, per2) == 0) x = min(x, sqrt(norm(b - per2)));
			if (ccw(a, b, per3) == 0) x = min(x, sqrt(norm(c - per3)));
			if (ccw(a, b, per4) == 0) x = min(x, sqrt(norm(d - per4)));
		}
	}
	return x;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		vector<point> p[505];
		int r1, r2, n;
		scanf("%d%d%d", &r1, &r2, &n);
		loop(i, 0, r1 - 1) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			p[0].push_back(point(x, y));
		}
		loop(i, 0, r2 - 1) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			p[1].push_back(point(x, y));
		}
		loop(i, 0, n - 1) {
			int r;
			scanf("%d",&r);
			loop(j, 0, r - 1) {
				double x, y;
				scanf("%lf%lf", &x, &y);
				p[i + 2].push_back(point(x, y));
			}
			p[i + 2].push_back(p[i + 2][0]);
		}
		n += 2;
		loop(i, 0, n - 1) {
			loop(j, 0, n - 1) {
				if (i == j) continue;
				adj[i][j] = mindist(p[i], p[j]);
			}
		}
		loop(k,0,n-1)
			loop(i, 0, n - 1)
			loop(j, 0, n - 1) {
			if (i == j) continue;
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		}
		printf("%.3lf\n",adj[0][1]);
	}
}