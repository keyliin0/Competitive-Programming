/*
	use inclusion exclusion principle
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
int k;
ll t[20];
// 55
ll res;


ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

ll LCM(ll a,ll b) {
	return (a*b) / GCD(a, b);
}

void solve(int i,int took,ll x) {
	if (i == k) {
		if (!took) return;
		if (took % 2 == 0) res -= n / x;
		else res += n / x;
		return;
	}
	solve(i + 1, took + 1, LCM(x, t[i]));
	solve(i + 1, took, x);
}

int main() {
	cin >> n >> k;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	loop(i, 0, k - 1)
		cin >> t[i];
	solve(0, 0, 1);
	cout << n - res;
}