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

int n, m;
int ans[N];

struct Q{
	int type, l, r, d;
};

Q q[5005];
int diff[5005];
int curr[5005];

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 1, n)
		ans[i] = oo;
	loop(i, 0, m - 1) {
		scanf("%d%d%d%d", &q[i].type, &q[i].l, &q[i].r, &q[i].d);
	}
	loop(i, 0, m - 1) {
		if (q[i].type == 1) {
			loop(j, q[i].l, q[i].r) diff[j] += q[i].d;
		}
		else {
			loop(j, q[i].l, q[i].r) ans[j] = min(ans[j], q[i].d - diff[j]);
		}
	}
	loop(i, 0, m - 1) {
		if (q[i].type == 1) {
			loop(j, q[i].l, q[i].r) curr[j] += q[i].d;
		}
		else {
			int mx = -oo;
			loop(j, q[i].l, q[i].r) mx = max(mx, ans[j] + curr[j]);
			if (mx != q[i].d) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	loop(i, 1, n) {
		printf("%d ",ans[i]);
	}
}