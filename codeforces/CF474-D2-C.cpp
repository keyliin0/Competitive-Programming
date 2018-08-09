/*
	each point can have 4 possible rotations,brute force will work since 4^4 (each point have 4 possible rotations and we have 4 points ) not too big
	to rotate a point (x,y) 90 degree counter-clockwise around another point (a,b)
	new point = (- (y - b) + a , (x - a) + b) see https://math.stackexchange.com/questions/2138328/90-degree-counter-clockwise-rotation-around-a-point
	to check if 4 points form a square :
	https://www.geeksforgeeks.org/check-given-four-points-form-square/
	or https://softwareengineering.stackexchange.com/questions/176938/how-to-check-if-4-points-form-a-square
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

int n, ans;

struct Point{
	int x, y;
};

pair<Point,Point> t[4];

int distSq(Point p, Point q){
	return (p.x - q.x)*(p.x - q.x) +
		(p.y - q.y)*(p.y - q.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
	int d2 = distSq(p1, p2);  // from p1 to p2
	int d3 = distSq(p1, p3);  // from p1 to p3
	int d4 = distSq(p1, p4);  // from p1 to p4

							  // If lengths if (p1, p2) and (p1, p3) are same, then
							  // following conditions must met to form a square.
							  // 1) Square of length of (p1, p4) is same as twice
							  //    the square of (p1, p2)
							  // 2) p4 is at same distance from p2 and p3
	if (d2 == d3 && 2 * d2 == d4)
	{
		int d = distSq(p2, p4);
		return (d == distSq(p3, p4) && d == d2);
	}

	// The below two cases are similar to above case
	if (d3 == d4 && 2 * d3 == d2)
	{
		int d = distSq(p2, p3);
		return (d == distSq(p2, p4) && d == d3);
	}
	if (d2 == d4 && 2 * d2 == d3)
	{
		int d = distSq(p2, p3);
		return (d == distSq(p3, p4) && d == d2);
	}

	return false;
}

void rotate(int idx,Point p1,Point p2) {
	Point tmp;
	tmp.x = p2.x - (p1.y - p2.y);
	tmp.y = p2.y + p1.x - p2.x;
	t[idx].first = tmp;
}

void solve(int idx,int curr) {
	if (idx == 4) {
		bool ok = 1;
		loop(i, 0, 3) {
			loop(j, i + 1, 3) {
				if (t[i].first.x == t[j].first.x && t[i].first.y == t[j].first.y) ok = 0;
			}
		}
		if (ok && isSquare(t[0].first, t[1].first, t[2].first, t[3].first)) ans = min(ans, curr);
		return;
	}
	solve(idx + 1, curr);
	loop(i, 1, 3) {
		rotate(idx, t[idx].first, t[idx].second);
		solve(idx + 1, curr + i);
	}
	rotate(idx, t[idx].first, t[idx].second);
}


int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		loop(j, 0, 3)
			scanf("%d%d%d%d", &t[j].first.x, &t[j].first.y, &t[j].second.x, &t[j].second.y);
		ans = oo;
		solve(0,0);
		printf("%d\n", ans == oo ? -1 : ans);
	}

}