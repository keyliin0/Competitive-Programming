/*
	there is an O(n) sol using a stack
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
int seg[N];

int get(int p, int s, int e, int l, int r) {
	if (s >= l && e <= r)
		return seg[p];
	if (s > r || e < l)
		return 0;
	return max(get(2 * p, s, (s + e) / 2, l, r), get(2 * p + 1, (s + e) / 2 + 1, e, l, r));
}

void build(int p, int s, int e) {
	if (s == e) {
		seg[p] = t[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = max(seg[2 * p], seg[2 * p + 1]);
}

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	build(1, 0, n - 1);
	int ans = 0;
	loop(i, 0, n - 2) {
		int l = 1, r = n - i - 1;
		int len = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(1, 0, n - 1, i + 1, i + m) > t[i]) {
				len = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (len) ans = max(ans, t[i] ^ t[i + len]);
	}
	loop2(i, n - 1, 1) {
		int l = 1, r = i;
		int len = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(1, 0, n - 1, i - m, i - 1) > t[i]) {
				len = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (len) ans = max(ans, t[i] ^ t[i - len]);
	}
	printf("%d",ans);
}