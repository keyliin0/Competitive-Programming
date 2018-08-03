/*
	we cant calculate Z because it may overflow
	if we start caulculating Zs each second and we have Zs = T then we know that the needed time will be
	n - s
	otherwise if Zs > t at s then we need n - s + 1
	if t > final Z then the ans is 0
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

ll k, b, n, t;

int main() {
	scanf("%lld%lld%lld%lld", &k, &b, &n, &t);
	ll curr = 1;
	while (curr < t && n) {
		curr = k * curr + b;
		if (curr > t) break;
		n--;
	}
	printf("%lld",n);
}