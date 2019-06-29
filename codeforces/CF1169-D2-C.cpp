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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
int n, m;
int t[N];
 
bool can(int k) {
	int prev = t[1];
	if (t[1] + k >= m) prev = 0;
	loop(i, 2, n) {
		if (prev >= t[i]) {
			int need = prev - t[i];
			if (need > k) return 0;
		}
		else {
			if (m - t[i] + prev <= k) continue;
			prev = t[i];
		}
	}
	return 1;
}
 
int main() {
	scanf("%d%d", &n, &m);
	bool f = 1;
	loop(i, 1, n) {
		scanf("%d",&t[i]);
		if (t[i] < t[i - 1]) f = 0;
	}
	if (f) {
		printf("0");
		return 0;
	}
	int l = 1, r = m;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (can(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d",ans);
}