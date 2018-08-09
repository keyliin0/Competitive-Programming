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

int n,m;
vector<int> v;
int t[1009];
ll inv[1005], f[1005];

ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) % mod * a) % mod;
	return (res*res) % mod;
}

ll nCk(ll n, ll k) {
	return ((f[n] * inv[k]) % mod*inv[n - k]) % mod;
}


int main() {
	f[0] = 1;
	inv[0] = fastPower(1, mod - 2);
	for (int i = 1; i <= 1002; ++i) {
		f[i] = (i * f[i - 1]) % mod;
		inv[i] = fastPower(f[i], mod - 2);
	}
	scanf("%d%d",&n,&m);
	loop(i, 0, m - 1) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	t[0] = v[0] - 1;
	loop(i, 1, m - 1) {
		t[i] = v[i] - v[i - 1] - 1;
	}
	t[m] = n - v[m - 1];
	ll ans = 1;
	loop(i, 1, m - 1)
		ans = (ans * fastPower(2, t[i] - 1)) % mod;
	ll curr = t[0];
	loop(i, 1, m) {
		curr += t[i];
		ans = (ans * nCk(curr, t[i])) % mod;
	}
	printf("%lld",ans);
	
}