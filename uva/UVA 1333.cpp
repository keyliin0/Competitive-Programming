#include <bits/stdc++.h>
#include <unordered_map>
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

double d, h, a, b, c;

int main() {
	scanf("%lf%lf", &d, &h);
	while (1) {
		scanf("%lf%lf%lf", &a, &b, &c);
		if (a <= 0 || b <= 0 || c <= 0) return 0;
		a = tan(a * PI / 180.0);
		b = tan(b * PI / 180.0);
		c = tan(c * PI / 180.0);
		double ans = d * sqrt(2 / (1 / a / a + 1 / c / c - 2 / b / b)) + h;
		printf("%.0lf\n", ans);
	}
	return 0;
}