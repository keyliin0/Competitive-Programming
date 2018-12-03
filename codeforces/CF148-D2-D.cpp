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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int w, b;
double dp[1005][1005];

double solve(int ww,int bb,bool pri) {
	if (bb < 0) return 0.0;
	if (ww == 0) return 0.0;
	if (bb == 0) {
		if (pri) return 1.0;
		else return 0.0;
	}
	double &ret = dp[ww][bb];
	if (ret == ret) return ret;
	double w = ww;
	double b = bb;
	if (pri) {
		ret = w / (w + b);
		ret += (b / (w + b)) * solve(w, b - 1, !pri);
	}
	else {
		ret = (b / (w + b)) * ((b  - 1) / (w + b - 1)) * solve(w, b - 2, !pri);
		ret += (b / (w + b)) * (w / (w + b - 1)) * solve(w - 1, b - 1, !pri);
	}
	return ret;
}

int main() {
	scanf("%d%d", &w, &b);
	memset(dp, -1, sizeof dp);
	double ans = solve(w, b, 1);
	printf("%.9lf",ans);
}