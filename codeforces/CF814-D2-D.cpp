/*
	sort circles by radius
	if we can put the current circle in the first or second space such that it is inside an even number of circles
	then add the surface to the answer otherwise add the circle to the first (or second) space and subtract the surface
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

struct circle{
	ll x, y, r;
};

circle t[1005];
vector<circle> v1, v2;
int n;

double dist(ll x, ll y, ll xx, ll yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

bool compare(circle i,circle y) {
	return i.r > y.r;
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%lld%lld%lld",&t[i].x,&t[i].y,&t[i].r);
	}
	sort(t, t + n, compare);
	double ans = 0;
	loop(i, 0, n - 1) {
		int cover = 0;
		for (int j = 0; j < v1.size(); j++) {
			if (dist(t[i].x, t[i].y, v1[j].x, v1[j].y) <= v1[j].r) cover++;
		}
		if (cover % 2 == 0) {
			v1.push_back(t[i]);
			ans += t[i].r * t[i].r * PI;
		}
		else {
			cover = 0;
			for (int j = 0; j < v2.size(); j++) {
				if (dist(t[i].x, t[i].y, v2[j].x, v2[j].y) <= v2[j].r) cover++;
			}
			if (cover % 2 == 0) {
				v2.push_back(t[i]);
				ans += t[i].r * t[i].r * PI;
			}
			else {
				v1.push_back(t[i]);
				ans -= t[i].r * t[i].r * PI;
			}
		}
	}
	printf("%.9f", ans);
}