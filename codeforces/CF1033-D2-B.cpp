/*
	x = a * a - b * b 
	= a^2  - b^2 
	= (a - b) * (a + b)
	x is prime if (a - b) is 1 and (a + b) is prime or the opposite so we check if (a + b) is prime and if (a - b) = 1
	otherwise the answer is NO
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

int n;

int main() {
	scanf("%d", &n);
	while (n--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a - b != 1) {
			printf("NO\n");
			continue;
		}
		bool yes = 1;
		for (ll i = 2; i * i <= a + b; i++) {
			if ((a + b) % i == 0) {
				yes = 0;
			}
		}
		if(yes) printf("YES\n");
		else printf("NO\n");
	}
	
}