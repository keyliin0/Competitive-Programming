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

ll t[N];
int n;
ll s;

bool can(ll x) {
	ll cnt = 0;
	loop(i, 0, n - 1) {
		cnt += t[i] - x;
	}
	return cnt >= s;
}

int main() {
	scanf("%d%lld", &n, &s);
	loop(i, 0, n - 1)
		scanf("%lld",&t[i]);
	sort(t, t + n);
	ll l = 0, r = t[0], ans = -1;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (can(m)) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%lld",ans);
}