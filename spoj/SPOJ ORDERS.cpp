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

int seg[4*200005];
int n;
int ans[N];
int t[N];
// 40

void build(int p,int s,int e) {
	if (s == e) {
		seg[p] = 1;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int get(int p,int s,int e,int k) {
	if (s == e) {
		return s;
	}
	if (seg[2 * p] >= k) return get(2 * p, s, (s + e) / 2, k);
	return get(2 * p + 1, (s + e) / 2 + 1, e, k - seg[2 * p]);
}

void update(int p,int s,int e,int i) {
	if (s == e) {
		seg[p] = 0;
		return;
	}
	if (i <= (s + e) / 2) update(2 * p, s, (s + e) / 2, i);
	else update(2 * p + 1, (s + e) / 2 + 1, e, i);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		build(1, 1, n);
		loop(i, 0, n - 1) {
			scanf("%d",&t[i]);
		}
		loop2(i, n - 1, 0) {
			ans[i] = get(1, 1, n, i + 1 - t[i]);
			update(1, 1, n, ans[i]);
		}
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}