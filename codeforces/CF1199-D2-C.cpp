#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
int n;
ll s;
vector<ll> v;
 
int main() {
	scanf("%d%lld", &n, &s);
	loop(i, 0, n - 1) {
		ll x;
		scanf("%lld", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<ll> v2;
	v2.push_back(v[0]);
	loop(i, 1, n - 1) {
		if (v[i] != v[i - 1]) v2.push_back(v[i]);
	}
	ll k = -1;
	ll l = 1, r = n;
	while (l <= r) {
		ll m = (l + r) / 2;
		ll x = ceil(log2(m));
		if (x * 1LL * n <= s * 8) {
			k = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	ll ans = oo;
	for (int i = 0; i + k - 1 < v2.size(); i++) {
		ll l = v2[i];
		ll r = v2[i + k - 1];
		ll curr = (lower_bound(v.begin(), v.end(), l) - v.begin()) + (v.end() - upper_bound(v.begin(), v.end(), r));
		ans = min(ans, curr);
	}
	printf("%lld", (ans == oo ? 0 : ans));
}