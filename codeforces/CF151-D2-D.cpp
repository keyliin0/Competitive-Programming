/*
	if we trace some test cases we can see that if n is even we can only use one character so answer is n
	if n is odd then we can alternate between two characters so the answer = number of ways to choose first character * number of ways to choose second character = m^2
	if n = 1 or k > n answer = number of ways to choose a character n times = m^n
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

int n, m, k;

ll fastpower(ll a,ll p) {
	if (p == 0) return 1;
	ll res = fastpower(a, p / 2);
	if (p % 2 == 0) return (res * res) % mod;
	else return (((res * res) % mod) * a) % mod;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	if (k == 1 || k > n) printf("%lld", fastpower(m, n));
	else if (k == n) printf("%lld", fastpower(m, (n + 1) / 2));
	 else if(k % 2 == 0) printf("%d", m);
	 else printf("%d", m * m);
}