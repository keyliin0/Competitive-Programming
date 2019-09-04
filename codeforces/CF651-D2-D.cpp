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
ll a, b;
ll T;
char s[N];

int main() {
	scanf("%d%lld%lld%lld%s", &n, &a, &b, &T, s);
	vector<ll> v;
	ll curr = 0;
	loop2(i, n - 1, 0) {
		if (s[i] == 'w') curr += b;
		curr++;
		v.push_back(curr);
		curr += a;
	}
	
	ll rem = T;
	int ans = 0;
	loop(i, 0, n - 1) {
		if (s[i] == 'w') rem -= b;
		rem--;
		if (rem < 0) break;
		int x = upper_bound(v.begin(), v.end(), rem - (i + 1) * a) - v.begin();
		ans = max(ans, i + 1 + x);
		rem -= a;
	}
	curr = 0;
	v.clear();
	loop(i, 1, n - 1) {
		if (s[i] == 'w') curr += b;
		curr++;
		v.push_back(curr);
		curr += a;
	}
	rem = T - a - 1 - (s[0] == 'w') * b;
	loop2(i, n - 1, 0) {
		if (s[i] == 'w') rem -= b;
		rem--;
		if (rem < 0) break;
		int x = upper_bound(v.begin(), v.end(), rem - (n - i + 1) * a) - v.begin();
		ans = max(ans, n - i + x + 1);
		rem -= a;
	}
	printf("%d",min(ans,n));
}