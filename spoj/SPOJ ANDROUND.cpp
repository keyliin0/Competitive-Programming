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
int k;

void build(int p, int s, int e) {
	if (s == e) {
		seg[p] = t[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[2 * p] & seg[2 * p + 1];
}

int get(int p, int s, int e, int l, int r) {
	if (s > r || e < l) return -1;
	if (s >= l && e <= r) return seg[p];
	int p1 = get(2 * p, s, (s + e) / 2, l, r);
	int p2 = get(2 * p + 1, (s + e) / 2 + 1, e, l, r);
	if (p1 == -1) return p2;
	else if (p2 == -1) return p1;
	else return p1 & p2;
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d", &n, &k);
		k = min(k, n);
		loop(i, 1, n) {
			scanf("%d",&t[i]);
		}
		loop(i, n + 1, 3 * n)
			t[i] = t[i - n];
		build(1, 1, 3 * n);
		loop(i, n + 1, 2 * n) {
			int res = get(1, 1, 3 * n, i - k, i + k);
			printf("%d ", res);
		}
		printf("\n");
	}
}