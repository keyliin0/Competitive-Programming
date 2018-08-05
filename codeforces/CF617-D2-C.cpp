/*
	sort all points comparing to the distance to the center of the first circle
	now we know that all the points from 1 to i are covered by first circle so we need just to check the radius of the other circle
	which is max the distance from the center to all i + 1 to n points	
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
pair<double, double> t[N];
double x, y, xx, yy;

double dist(double x, double y, double xx, double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

bool compare(pair<double, double> i, pair<double, double> j) {
	return dist(x, y, i.first, i.second) < dist(x, y, j.first, j.second);
}

int main() {
	scanf("%d%lf%lf%lf%lf", &n, &x, &y, &xx, &yy);
	loop(i, 0, n - 1)
		scanf("%lf%lf", &t[i].first, &t[i].second);
	double ans = 1e18;
	double r3 = 0;
	sort(t, t + n, compare);
	loop(i, 0, n - 1) {
		r3 = max(r3, dist(xx, yy, t[i].first, t[i].second));
		double r1 = dist(x, y, t[i].first, t[i].second);
		double r2 = 0;
		loop(j, i + 1, n - 1) {
			r2 = max(r2, dist(xx, yy, t[j].first, t[j].second));
		}
		ans = min(ans, r2 * r2 + r1 * r1);
	}
	ans = min(ans, r3);
	printf("%.0lf", ans);
}