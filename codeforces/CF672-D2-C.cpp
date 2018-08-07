/*
	we know that after Adil and Bera make a move the distance will be distance from the bin to all the bottles * 2
	so the answer depends on the first bottle they go to
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
double x, y, xx, yy,tx,ty;
pair<double, double> t[N];
double dp[100005][2][2];
double total = 0;

double distance(double x,double y,double xx,double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

double calc(int i,bool f1,bool f2) {
	if (f1 && f2) return total;
	if (i == n) {
		if (f1 || f2) return total;
		return 1e18;
	}
	double &ret = dp[i][f1][f2];
	if (ret != -1) return ret;
	ret = 1e18;
	if (!f1) ret = min(ret, distance(x, y, t[i].first, t[i].second) - distance(t[i].first, t[i].second, tx, ty) + calc(i + 1, 1, f2));
	if (!f2) ret = min(ret, distance(xx,yy, t[i].first, t[i].second) - distance(t[i].first, t[i].second, tx, ty) + calc(i + 1, f1, 1));
	ret = min(ret, calc(i + 1, f1, f2));
	return ret;
}

int main() {
	scanf("%lf%lf%lf%lf%lf%lf%d", &x, &y, &xx, &yy, &tx, &ty,&n);
	loop(i, 0, n - 1) {
		scanf("%lf%lf", &t[i].first, &t[i].second);
		total += 2.0  * distance(t[i].first, t[i].second, tx, ty);
		loop(j, 0, 1)
			loop(k, 0, 1)
				dp[i][j][k] = -1;
	}
	double ans = calc(0, 0, 0);
	printf("%.6lf",ans);
}