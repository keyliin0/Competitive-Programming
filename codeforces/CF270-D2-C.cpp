/*
	each box with length K can hold 4 times the previous one and 4*4 the one with K - 2 length
	if we want to give each box a capicity it would be 4^k
	let s be the answer where so 4^s >= 4^kmax * a
	since we're looking for the minimum answer 4^s = 4^kmax * a 
	4^(s - kmax) = a
	s -	kmax = log4(a)
	s = log4(a) + kmax
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

int n;

int main() {
	scanf("%d",&n);
	ll ans = 0;
	loop(i, 0, n - 1) {
		ll k, a;
		scanf("%lld%lld",&k,&a);
		ll lg = log10(a) / log10(4);
		ll p = pow(4, lg);
		if (p != a) lg++;
		ans = max(ans, k + lg);
		if (ans == k) ans++;
	}
	printf("%lld",ans);
}