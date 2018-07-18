/*
	first find all angles for all points
	sort the point based on the angles
	and check if the  360 - (i + 1 point angle - the ith point angle) is less than the current answer
	we know that i + 1 point angle - the ith point angle will give us the angle between the 2 points but we need to cover all the point except these
	two points so we take the complement which is 360 - the angle between the two points
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
//typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

struct point{
	int x, y;
	double angle;
};

point t[N];
int n;

double getangle(int x,int y) {
	double a = acos(x / sqrt(x * x + y * y));
	if (y >= 0) return a;
	else return 2 * PI - a;
}

bool compare(point a, point b) {
	return a.angle < b.angle;
}

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		scanf("%d%d", &t[i].x, &t[i].y);
		t[i].angle = getangle(t[i].x, t[i].y);
	}
	sort(t, t + n,compare);
	double ans = t[n - 1].angle - t[0].angle;
	loop(i, 0, n - 2) {
		ans = min(ans, 2 * PI - (t[i + 1].angle - t[i].angle));
	}
	printf("%.6f",ans * 180 / PI);
}