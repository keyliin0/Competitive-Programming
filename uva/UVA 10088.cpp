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
const double EPS = 1e-18;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
vector<point> t;

double polygonArea(vector<point>& points) {
	long double a = 0;
	loop(i, 0, points.size() - 1)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

double countboundaries(vector<point>& points) {
	long double a = 0;
	loop(i, 0, points.size() - 1)
		a += GCD(abs(points[i].X - points[(i + 1) % points.size()].X) , abs(points[i].Y - points[(i + 1) % points.size()].Y));
	return a;
}

int main() {
	while (scanf("%d", &n) && n) {
		t.clear();
		loop(i, 0, n - 1) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			t.push_back(point(x, y));
		}
		double a = polygonArea(t);
		double b = countboundaries(t);
		ll ans = a - b / 2 + 1;
		printf("%lld\n",ans);
	}
}