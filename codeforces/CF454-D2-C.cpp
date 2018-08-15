/*
	for the ith value we have i^n possibilities which may or may not include i as a maximum so
	subtruct (i-1)^n from i^n and get number of appearance of i as a max and apply expected value formula
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

int n, m;

double fastPower(double a, int b) {
	if (b == 0)
		return 1;
	double res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return res * res * a;
	return res*res;
}

int main() {
	scanf("%d%d",&m,&n);
	double ans = 0;
	loop(i, 1, m) {
		ans += i * (fastPower((double)i / m, n) - fastPower((double)(i - 1) / m, n));
	}
	printf("%.4lf", ans);
}