#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int a[N], b[N], seg[N][2];
int n;

void build(int p, int s, int e) {
	if (s == e) {
		seg[p][0] = a[s];
		seg[p][1] = b[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p][0] = max(seg[2 * p][0], seg[2 * p + 1][0]);
	seg[p][1] = min(seg[2 * p][1], seg[2 * p + 1][1]);
}

pair<int, int> get(int p, int s, int e, int a, int b) {
	if (s >= a && e <= b)
		return { seg[p][0],seg[p][1] };
	if (s > b || e < a)
		return { -oo , oo };
	pair<int, int> p1 = get(2 * p, s, (s + e) / 2, a, b);
	pair<int, int> p2 = get(2 * p + 1, (s + e) / 2 + 1, e, a, b);
	return { max(p1.first,p2.first) , min(p1.second,p2.second) };
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1)
		scanf("%d", &a[i]);
	loop(i, 0, n - 1)
		scanf("%d", &b[i]);
	build(1, 0, n - 1);
	ll ans = 0;
	loop(i, 0, n - 1) {
		int l = i, r = n - 1, left = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			pair<int, int> p = get(1, 0, n - 1, i, m);
			if (p.first >= p.second) {
				if (p.first == p.second) left = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (left == -1) continue;
		l = left, r = n - 1;
		int right = left;
		while (l <= r) {
			int m = (l + r) / 2;
			pair<int, int> p = get(1, 0, n - 1, i, m);
			if (p.first == p.second) {
				right = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		ans += right - left + 1;
	}
	printf("%lld", ans);
}