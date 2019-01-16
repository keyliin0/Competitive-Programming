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

int n;
ll t[N];
ll dp[N][2];
int vis[N][2];

ll calc(int i, int add) {
	if (i <= 0 || i > n) return 0;
	if (vis[i][add] == 1) return dp[i][add] = -1e17;
	ll &ret = dp[i][add];
	if (vis[i][add]) return ret;
	vis[i][add] = 1;
	if (add) ret = t[i] + calc(i + t[i], 0);
	else ret = t[i] + calc(i - t[i], 1);
	vis[i][add] = 2;
	return ret;
}

int main() {
	scanf("%d",&n);
	loop(i, 2, n)
		scanf("%lld", &t[i]);
	loop(i, 1, n - 1) {
		t[1] = i;
		ll y = i;
		y += calc(i + 1, 0);
		printf("%lld\n",(y < -1e15 ? -1 : y));
	}
}