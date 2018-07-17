/*
	n = (a - 1) * (b - 2) * (c - 2)
	if we solve n /(a - 1) * (b - 2) = (c - 2) we can find the ans
	(a - 1) & (b - 2) must be divisors of n
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

ll n;
vector<ll> v;

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (i * i != i) v.push_back(n / i);
		}
	}
	ll mx = -1, mn = 1e18;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			ll c = n / (v[i] * v[j]);
			if (n % (v[i] * v[j]) != 0) continue;
			ll x = (v[i] + 1) * (v[j] + 2) * (c + 2);
			mx = max(mx, x - n);
			mn = min(mn, x - n);
			x = (v[i] + 2) * (v[j] + 1) * (c + 2);
			mx = max(mx, x - n);
			mn = min(mn, x - n);
			x = (v[i] + 2) * (v[j] + 2) * (c + 1);
			mx = max(mx, x - n);
			mn = min(mn, x - n);
		}
	}
	printf("%lld %lld", mn, mx);
}