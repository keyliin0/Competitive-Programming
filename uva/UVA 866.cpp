/* 
	it two segment intersect then we will have 2 new segments
	so we check how many segment intersect and calculate the answer
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
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
pair<point,point> t[N];

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
	scanf("%d",&tests);
	loop(tt, 0, tests - 1) {
		if (tt) printf("\n");
		scanf("%d",&n);
		loop(i, 0, n - 1) {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			t[i].first = point(x1, y1);
			t[i].second = point(x2, y2);
		}
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (intersect(t[i].first, t[i].second, t[j].first, t[j].second)) ans+=2;
			}
		}
		printf("%d\n",ans);
	}
}
