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
vector<point> t;

bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS) return false; // Parllel || identical
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a)*t1;
	if (t2 < -EPS || t2 > 1 + EPS)
		return false;
	return true;
}

double polygonArea(vector<point>& points) {
	long double a = 0;
	loop(i, 0, points.size() - 1)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}

pair<double,double > polygonCut(vector<point> &p,point A, point B) {

	vector<point> left, right;
	point intersect;

	for (int i = 0; i < p.size(); ++i) {
		point cur = p[i], nxt = p[(i + 1) % p.size()];

		if (cp(B - A, cur - A) >= 0)
			right.push_back(cur);

		if (cp(B - A, cur - A) <= 0)
			left.push_back(cur);
		//NOTE adust intersectSegments should handled AB as line
		if (intersectSegments(A, B, cur, nxt, intersect)) {
			right.push_back(intersect);
			left.push_back(intersect);
		}

	}
	return make_pair(polygonArea(left), polygonArea(right));
}


int main() {
	int cas = 0;
	while (1) {
		t.clear();
		bool end = 1;
		vector<point> v;
		loop(i, 0, 3) {
			int x, y;
			scanf("%d%d",&x,&y);
			if (x != 0 || y != 0) end = 0;
			v.push_back(point(x, y));
		}
		loop(i, 0, 3) {
			t.push_back(v[i]);
			t.push_back(point((v[i].X + v[(i + 1) % 4].X) / 2.0, (v[i].Y + v[(i + 1) % 4].Y) / 2.0));
		}
		if (end) return 0;
		double a = polygonArea(t);
		double diff = 1e18;
		double ans1, ans2;
		loop(i, 0, t.size() - 1) {
			loop(j, i + 1, t.size() - 1) {
				//vector<point> p1 = polygonCut(t, t[i], t[j]).first;
				pair<double, double> aa = polygonCut(t, t[i], t[j]);
				if (abs(aa.first - aa.second) < diff) {
					diff = abs(aa.first - aa.second);
					ans1 = min(aa.first,aa.second);
					ans2 = max(aa.first, aa.second);
				}
			//	printf("%.9lf %.9lf\n",aa.first,aa.second);
			}
		}
		printf("Cake %d: %.3lf %.3lf\n",++cas,ans1,ans2);
	}
}