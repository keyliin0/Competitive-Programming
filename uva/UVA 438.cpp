/* 
	with three non-collinear points with can get the center
	and so the radius and calculate the circumference 
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

double xx1, xx2, xx3, yy1, yy2, yy3;

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

int main() {
	while (scanf("%lf%lf%lf%lf%lf%lf", &xx1, &yy1, &xx2, &yy2, &xx3, &yy3) != EOF) {
		double r = findCircle(point(xx1, yy1), point(xx2, yy2), point(xx3, yy3)).first;
		double ans = 2.0 * r * PI;
		printf("%.2f\n",ans);
	}
}
