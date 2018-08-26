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
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, k;
int t[100005][6], ans[6], seg[4 * 100005][6], t2[6];

void update(int p,int s,int e,int i) {
	if (s == e) {
		loop(j, 0, m - 1)
			seg[p][j] = t[i][j];
		return;
	}
	if (i <= (s + e) / 2) update(2 * p, s, (s + e) / 2, i);
	else update(2 * p + 1, (s + e) / 2 + 1, e, i);
	loop(j, 0, m - 1)
		seg[p][j] = max(seg[2 * p][j], seg[2 * p + 1][j]);
}

void get(int p,int s,int e,int l,int r) {
	if (s >= l && e <= r) {
		loop(i, 0, m - 1)
			t2[i] = max(t2[i], seg[p][i]);
		return;
	}
	if (s > r || e < l) return;
	get(2 * p, s, (s + e) / 2, l, r);
	get(2 * p + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1)
			scanf("%d", &t[i][j]);
		update(1, 0, n - 1, i);
	}
	int mx = 0, start, end;
	loop(i, 0, n - 1) {
		int l = i, r = n - 1;
		while (l <= r) {
			memset(t2, -1, sizeof t2);
			int mid = (l + r) / 2;
			get(1, 0, n - 1, i, mid);
			ll sum = 0;
			loop(j, 0, m - 1)
				sum += t2[j];
			if (sum <= k) {
				if (mid - i + 1 > mx) {
					mx = mid - i + 1;
					start = i;
					end = mid;
				}
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	if (mx) {
		loop(i, start, end) {
			loop(j, 0, m - 1) {
				ans[j] = max(ans[j], t[i][j]);
			}
		}
	}
	loop(i, 0, m - 1)
		printf("%d ",ans[i]);
}