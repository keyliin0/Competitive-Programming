/*
	this code fails but I read there is a problem with uva official answer
	try :
	1
	2 -5 -10 3 -1 0 2 -3
	http://www.uvatoolkit.com/problemssolve.php
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
point t[4];

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
	scanf("%d", &tests);
	while (tests--) {
		int x, y;
		scanf("%d%d", &x, &y);
		point p1 = point(x, y);
		scanf("%d%d", &x, &y);
		point p2 = point(x, y);
		bool yes = 0;
		loop(i, 0, 1) {
			scanf("%d%d", &x, &y);
			t[i] = point(x, y);
		}
		yes |= intersect(p1, p2, t[0], point(t[1].X, t[0].Y)) | intersect(p1, p2, t[0], point(t[0].X, t[1].Y)) | intersect(p1, p2, t[1], point(t[1].X, t[0].Y)) | intersect(p1, p2, t[1], point(t[0].X, t[1].Y));
		yes |= (p1.X > t[0].X && p1.X < t[1].X && p1.Y < t[0].Y && p1.Y > t[1].Y) | (p2.X > t[0].X && p2.X < t[1].X && p2.Y < t[0].Y && p2.Y > t[1].Y);
		if (yes) printf("T\n");
		else printf("F\n");
	}
}