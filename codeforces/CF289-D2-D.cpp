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
 
int n, k;
int t[10];
bool vis[10];
 
ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) % mod * a) % mod;
	return (res*res) % mod;
}
 
ll ways1 = 0;
 
bool check() {
	loop(i, 1, k) {
		memset(vis, 0, sizeof vis);
		int idx = i;
		bool yes = 0;
		while (!vis[idx]) {
			vis[idx] = 1;
			idx = t[idx];
			if (idx == 1) yes = 1;
		}
		if (!yes) return 0;
	}
	return 1;
}
 
void generate(int idx) {
	if (idx == k + 1) {
		if (check()) ways1++;
		return;
	}
	loop(i, 1, k) {
		t[idx] = i;
		generate(idx + 1);
	}
}
 
int main() {
	scanf("%d%d",&n,&k);
	ll ways2 = fastPower(n - k, n - k);
	generate(1);
	ll ans = (ways1 * ways2) % mod;
	cout << ans;
}