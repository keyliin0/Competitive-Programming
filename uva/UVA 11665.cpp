/*
	two polygons are in the same component if they intersect or one of them is inside the other
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
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
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

int t;
int n;
int p[N];

int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a - b), ac = length(a - c), cb = length(b - c);
	return dcmp(acb - (ac + cb), 0) == 0;
}

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


int find(int u) {
	if (p[u] == u)
		return u;

	return p[u] = find(p[u]);
}

int main() {
	while (cin >> n && n) {
		vector<point> v[n];
		cin.ignore();
		for (int i = 0; i < n; i++) {
			p[i] = i;
			string line;
			getline(cin, line);
			istringstream iss(line);
			double x, y;
			while (iss >> x && iss >> y) {
				v[i].push_back(point(x, y));
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a = find(i);
				int b = find(j);
				if (a == b) continue;
				bool f = 0;
				for (int k1 = 0; k1 < v[i].size(); k1++)
					for (int k2 = 0; k2 < v[j].size(); k2++)
						if (intersect(v[i][k1], v[i][(k1 + 1) % v[i].size()], v[j][k2], v[j][(k2 + 1) % v[j].size()]) || isInsidePoly(v[i], v[j][k2]))
							f = 1;
				if (f) p[a] = b;
			}
		}
		loop(i, 0, n - 1)
			if (p[i] == i) ans++;
		cout << ans << "\n";
	}
}
