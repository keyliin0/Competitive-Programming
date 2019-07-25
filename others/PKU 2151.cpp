#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

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
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

double p[1005][50];
int n, m, t;
double s[1005][50];
double dp1[50][50],dp2[1005][2];

double solve1(int i,int rem,int c) {
	if (i == m) return rem == 0 ? 1.0 : 0.0;
	double &ret = dp1[i][rem];
	if (ret == ret) return ret;
	ret = 0;
	if (rem) ret += p[c][i] * solve1(i + 1, rem - 1, c);
	ret += (1.0 - p[c][i]) * solve1(i + 1, rem , c);
	return ret;
}

double solve2(int i,int champ, int k) {
	if (i == t) return champ;
	double &ret = dp2[i][champ];
	if (ret == ret) return ret;
	ret = 0;
	loop(j, 1, k) {
		ret += s[i][j] * solve2(i + 1, champ || j == k, k);
	}
	return ret;
}

int main() {
	while (scanf("%d%d%d",&m,&t,&n) && n) {
		loop(i, 0, t - 1) {
			loop(j, 0, m - 1) {
				scanf("%lf",&p[i][j]);
			}
		}
		loop(i, 0, t - 1) {
			loop(j, 1, m) {
				memset(dp1, -1, sizeof dp1);
				s[i][j] = solve1(0, j, i);
			}
		}
		double ans = 0;
		loop(i, n, m) {
			memset(dp2, -1, sizeof dp2);
			ans += solve2(0, 0,i);
		}
		printf("%.3lf\n",ans);
	}
}