/*
	go through all the powers of k while k^p < 10^4
	since we want how many prefix t[r] - t[l - 1] = p then add to the answer the number of occ of p + t[l - 1]
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

int n, k;
map<ll, int> mp;
ll t[N];

ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) * a);
	return (res*res);
}

int main() {
	scanf("%d%d",&n,&k);
	loop(i, 0, n - 1)
		scanf("%lld",&t[i]);
	mp[t[0]]++;
	loop(i, 1, n - 1) {
		t[i] += t[i - 1];
		mp[t[i]]++;
	}
	ll ans = 0;
	loop(i, 0, n - 1) {
		loop(j, 0, 64) {
			ll p = fastPower(k, j);
			if (abs(p) > 1e14 || (k == 1 && j == 1) || (k == -1 && j == 2)) break;
			ans += mp[p + (i == 0 ? 0 : t[i - 1])];
		}
		mp[t[i]]--;
	}
	printf("%lld",ans);
}