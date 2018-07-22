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
struct cir{
	double x, y, r, R;
};
cir t[3];

int main() {
	loop(i, 0, 1)
		cin >> t[i].x >> t[i].y >> t[i].r >> t[i].R;
	double d = sqrt((t[0].x - t[1].x) *(t[0].x - t[1].x) + (t[0].y - t[1].y) * (t[0].y - t[1].y));
	int ans = 0;
	if (d + t[1].r <= t[0].r || d + t[0].R <= t[1].r || d >= t[1].r + t[0].R) ans++;
	if (d + t[0].r <= t[1].r || d + t[1].R <= t[0].r || d >= t[0].r + t[1].R) ans++;
	if (d + t[1].R <= t[0].r || d + t[0].R <= t[1].R || d >= t[0].R + t[1].R) ans++;
	if (d + t[0].R <= t[1].r || d + t[1].R <= t[0].R || d >= t[1].R + t[0].R) ans++;
	printf("%d",ans);
}
