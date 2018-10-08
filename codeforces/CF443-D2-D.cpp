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

int n;
double t[N];

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%lf",&t[i]);
	sort(t, t + n);
	reverse(t, t + n);
	double ans = 0;
	if (t[0] == 1) {
		ans = 1;
		printf("%.9lf",ans);
		return 0;
	}
	double sum = 0, s = 1;
	loop(i, 0, n - 1) {
		s = s * (1.0 - t[i]);
		sum += t[i] / (1 - t[i]);
		ans = max(ans, sum * s);
	}
	printf("%.9lf", ans);
}