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
const int mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, k;
pair<ll, ll> t[N];

int main() {
	scanf("%d%d", &n, &k);
	loop(i, 0, n - 1) {
		scanf("%lld%lld",&t[i].second,&t[i].first);
	}
	sort(t, t + n);
	reverse(t, t + n);
	priority_queue<ll> q;
	ll len = 0;
	ll ans = 0;
	loop(i, 0, k - 1) {
		q.push(-t[i].second);
		len += t[i].second;
		ans = max(ans, len * t[i].first);
	}
	loop(i, k, n - 1) {
		if (-q.top() < t[i].second) {
			len -= -q.top();
			q.pop();
			q.push(-t[i].second);
			len += t[i].second;
		}
		ans = max(ans, len * t[i].first);
	}
	printf("%lld",ans);
}