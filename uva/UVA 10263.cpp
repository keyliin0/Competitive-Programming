/*
	min distance will be perpendicular distance from m to the line or to one of the ends
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

struct Point{
	double x, y;
};

double x, y;
int n;
Point t[N];

Point perpendicular_point(double x1, double y1, double x2, double y2, double x3, double y3) {
	double k = k = ((y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1)) / ((y2 - y1) *(y2 - y1) + (x2 - x1) * (x2 - x1));
	Point p;
	p.x = x3 - k * (y2 - y1);
	p.y = y3 + k * (x2 - x1);
	return p;
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

double dist(double x,double y,double xx,double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}


int main() {
	while (scanf("%lf%lf%d", &x, &y, &n) != EOF) {
		loop(i, 0, n) {
			scanf("%lf%lf", &t[i].x, &t[i].y);
		}
		double mn = 1e18, ansx, ansy;
		loop(i, 1, n) {
			Point p = perpendicular_point(t[i].x, t[i].y, t[i - 1].x, t[i - 1].y, x, y);
			if (ccw(point(t[i].x, t[i].y), point(t[i - 1].x, t[i - 1].y), point(p.x, p.y)) == 0 && dist(x, y, p.x, p.y) < mn) { // ccw to check if the point in the segment
				mn = dist(x, y, p.x, p.y);
				ansx = p.x;
				ansy = p.y;
			}
			if (dist(x, y, t[i - 1].x, t[i - 1].y) < mn) {
				mn = dist(x, y, t[i - 1].x, t[i - 1].y);
				ansx = t[i - 1].x;
				ansy = t[i - 1].y;
			}
			if (dist(x, y, t[i].x, t[i].y) < mn) {
				mn = dist(x, y, t[i].x, t[i].y);
				ansx = t[i].x;
				ansy = t[i].y;
			}
		}
		printf("%.4lf\n%.4lf\n",ansx,ansy);
	}
}