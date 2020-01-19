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

int t[300005][10];
int n;
pair<int, int> a[N];
int m;

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 1, n) {
		loop(j, 0, m - 1) scanf("%d", &t[i][j]);
	}
	a[0].first = 0;
	a[0].second = 1;
	loop(i, 1, n) {
		for (int mask = 0; mask < (1 << m); mask++) {
			int mn = 1e9;
			loop(j, 0, m - 1) {
				if (mask & (1 << j))
					mn = min(t[i][j], mn);
			}
			if (mn >= a[mask].first) a[mask].first = mn, a[mask].second = i;
		}
	}
	int mx = -1, ans1, ans2;
	int all = (1 << m) - 1;
	for (int mask = 0; mask < (1 << m); mask++) {
		int mn = 1e9;
		int x = all ^ mask;
		if (min(a[mask].first, a[x].first) > mx) {
			mx = min(a[mask].first, a[x].first);
			ans1 = a[mask].second;
			ans2 = a[x].second;
		}
	}
	printf("%d %d", ans1, ans2);
}