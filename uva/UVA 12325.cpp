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

ll n, s1, v1, s2, v2;

int main() {
	int test;
	scanf("%d",&test);
	int cas = 0;
	while (test--) {
		cas++;
		scanf("%lld%lld%lld%lld%lld", &n, &s1, &v1, &s2, &v2);
		ll ans = 0;
		for (ll i = 0; i < 100000; i++) {
			if (i * s1 <= n) ans = max(ans, i * v1 + ((n - (i * s1)) / s2) *v2);
			if (i * s2 <= n) ans = max(ans, i * v2 + ((n - (i * s2)) / s1) *v1);
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
}