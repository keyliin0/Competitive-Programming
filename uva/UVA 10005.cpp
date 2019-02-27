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

int n;
point t[105];
double r;

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;
	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}
pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b + a)*0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c)*0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair(length(a - center), center);
}

double dist(point a,point b) {
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

bool check(point p) {
	bool can = 1;
	loop(u, 0, n - 1) {
		double d = dist(p, t[u]);
		if (d - r > EPS) can = 0;
	}
	return can;
}


int main() {
	while (scanf("%d", &n) && n) {
		loop(i, 0, n - 1) {
			double x, y;
			scanf("%lf%lf",&x,&y);
			t[i] = point(x, y);
		}
		scanf("%lf",&r);
		bool yes = 0;
		loop(i, 0, n - 1) {
			loop(j, i + 1, n - 1) {
				point p1 = point((t[i].X + t[j].X) / 2.0,(t[i].Y + t[j].Y) / 2.0);
				if (check(p1)) yes = 1;
				loop(k, j + 1, n - 1) {
					pair<double, point> p = findCircle(t[i], t[j], t[k]);
					if (check(p.second)) yes = 1;
				}
			}
		}
		if (yes) printf("The polygon can be packed in the circle.\n");
		else printf("There is no way of packing that polygon.\n");
	}
}