/*
	it's clear that we must check the distance between current location and each router 
	if it's <= radius then the answer is yes
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

int n, y;
pair<Point, double> t[105];

double dist(double x,double y,double xx,double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}


int main() {
	int tests;
	scanf("%d", &tests);
	loop(tt, 1, tests) {
		scanf("%d%d",&n,&y);
		loop(i, 0, n - 1) {
			scanf("%lf%lf%lf", &t[i].first.x, &t[i].first.y, &t[i].second);
		}
		printf("Case %d:\n",tt);
		loop(j, 0, y - 1) {
			double x, y;
			scanf("%lf%lf",&x,&y);
			bool yes = 0;
			loop(i, 0, n - 1) {
				if (dist(x, y, t[i].first.x, t[i].first.y) <= t[i].second) {
					yes = 1;
					break;
				}
			}
			if (yes) printf("Yes\n");
			else printf("No\n");
		}
	}
}
