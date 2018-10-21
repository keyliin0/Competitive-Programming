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
ll t[N];

int main() {
	scanf("%d",&n);
	loop(i, 1, 2 * n)
		scanf("%lld",&t[i]);
	sort(t + 1, t + 2 * n + 1);
	ll ans = (t[n] - t[1]) * (t[2 * n] - t[n + 1]);
	for (int i = 2; i + n - 1 < 2 * n; i++) {
		ans = min(ans, (t[i + n - 1] - t[i]) * (t[2 * n] - t[1]));
	}
	printf("%lld",ans);
}