/*
	for each digit calculate how much it contribute to the answer
	notice that only the length of other numbers matter when considering a single digit
*/
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
 
int n;
int t[N];
ll cnt[15];
ll MOD = 998244353;
ll pw[55];
 
int main() {
	pw[0] = 1;
	loop(i, 1, 20) {
		pw[i] = pw[i - 1] * 1LL * 10;
		pw[i] %= MOD;
	}
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		cnt[(int)log10(t[i]) + 1]++;
	}
	ll ans = 0;
	loop(i, 0, n - 1) {
		int p = 0;
		int x = t[i];
		while (x) {
			ll d = x % 10;
			x /= 10;
			p++;
			loop(j, p, 2 * (p - 1)) {
				int need = j - p;
				ans += pw[j - 1] * cnt[need] * d * 2;
				ans %= MOD;
			}
			ans += pw[2 * p - 2] * cnt[p - 1] * d * 2;
			ans %= MOD;
			loop(j, p, 10) {
				ans += pw[2 * p - 1] * cnt[j] * d;
				ans %= MOD;
				ans += pw[2 * p - 2] * cnt[j] * d;
				ans %= MOD;
			}
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}