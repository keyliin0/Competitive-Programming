/*
	find all divisors of n
	we know that LCM(a,b) = (a * b) / GCD(a,b) 
	(a * b) must be equal to n so GCD(a,b) = 1
	if two divisors are coprime then increase answer
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll n;

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main() {
	while (1) {
		scanf("%lld",&n);
		if (n == 0) return 0;
		ll ans = 2;
		if (n == 1) {
			printf("1 1\n");
			continue;
		}
		vector<ll> v;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				v.push_back(i);
				if (n / i != i) v.push_back(n / i);
			}
		}
		ans += (ll)v.size();
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (GCD(v[i], v[j]) == 1) ans++;
			}
		}
		printf("%lld %lld\n", n, ans);
	}
}