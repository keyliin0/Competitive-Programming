/*
	to get number of all perfect squares we need 10^9 operation which wont fit int time :
	number of perfect squares in a range = floor(sqrt(r)) - floor(sqrt(l - 1))
	precalculate numbers having power >= 3 in 10^6 and use binary search to answer each query
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

int q;
vector<ll> all, v;

ll getsqrt(ll x) {
	ll l = 1, r = 1e9 ,ret = 0;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (m * m <= x) {
			ret = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return ret;
}

int main() {
	for(ll i = 2; i <= 1000000;i++) {
		ll p = i * i * i;
		ll previous = 0;
		double x = 1ll * i * i * i;
		while(x <= 1e18 && previous < p){
			ll a = getsqrt(p);
			if(a * a != p) all.push_back(p);
			previous = p;
			p *= i;
			x *= i;
		}
	}
	sort(all.begin(), all.end());
	v.push_back(all[0]);
	loop(i, 1, all.size() - 1)
		if (all[i] != all[i - 1]) v.push_back(all[i]);
	scanf("%d",&q);
	while (q--) {
		ll l, r;
		scanf("%lld%lld",&l,&r);
		ll ans = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
		ans += getsqrt(r) - getsqrt(l - 1);
		printf("%lld\n",ans);
	}
}