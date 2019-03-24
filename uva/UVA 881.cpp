/*
	sort the polygons by area
	if a point is not inside the smallest polygon , then check then next smaller one
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
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }
int t;
int n, p;

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a - b), ac = length(a - c), cb = length(b - c);
	return dcmp(acb - (ac + cb), 0) == 0;
}

// Accurate and efficient
int isInsidePoly(vector<point> p, point p0) {
	int wn = 0;  // the winding number counter

	for (int i = 0; i < p.size(); i++) {
		point cur = p[i], nxt = p[(i + 1) % p.size()];
		if (isPointOnSegment(cur, nxt, p0))
			return true;
		if (cur.Y <= p0.Y) {    // Upward edge
			if (nxt.Y > p0.Y && cp(nxt - cur, p0 - cur) > EPS)
				++wn;
		}
		else {                // Downward edge
			if (nxt.Y <= p0.Y && cp(nxt - cur, p0 - cur) < -EPS)
				--wn;
		}
	}
	return wn != 0;
}

double polygonArea(vector<point>& points) {
	long double a = 0;
	loop(i, 0, points.size() - 1)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}


bool cmp(pair<int, vector<point>> &i, pair<int, vector<point>> &j) {
	return polygonArea(i.second) < polygonArea(j.second);
}

int main() {
	io;
	cin >> t;
	while (t--) {
		cin >> n;
		pair<int, vector<point>> v[n];
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string line;
			getline(cin, line);
			istringstream iss(line);
			iss >> v[i].first;
			double x, y;
			while (iss >> x && iss >> y) {
				v[i].second.push_back(point(x, y));
			}
		}
		sort(v ,v + n,cmp);
		cin >> p;
		point pt[p + 1];
		for (int i = 0; i < p; i++) {
			int id;
			double x, y;
			cin >> id >> x >> y;
			pt[id] = point(x, y);
		}
		for (int i = 1; i <= p; i++) {
			bool f = 1;
			for (int j = 0; j < n; j++) {
				if (isInsidePoly(v[j].second, pt[i])) {
					f = 0;
					cout << i << " " << v[j].first << "\n";
					break;
				}
			}
			if (f) cout << i << " 0\n";
		}
		if (t) cout << "\n";
	}
}
