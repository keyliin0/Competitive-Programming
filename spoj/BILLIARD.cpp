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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int a, b, s, m, n;

int main() {
	while (1) {
		scanf("%d%d%d%d%d", &a, &b, &s, &m, &n);
		if (!a) return 0;
		double ans1 = atan2(n * b, m * a) * 180.0 / PI;
		double ans2 = hypot(1.0 * a * m / s, 1.0 * b * n / s);
		printf("%.2lf %.2lf\n", ans1, ans2);
	}
}