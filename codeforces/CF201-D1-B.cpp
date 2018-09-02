/*
	find min answer for the row and col since both answers are independent
*/
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

int n, m;
ll row[1005], col[1005];

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			int x;
			scanf("%d",&x);
			row[i] += x;
			col[j] += x;
		}
	}
	ll min_row = 1e18;
	int ans_row;
	loop(i, 0, n) {
		ll curr = 0;
		for (int j = i, x = 2; j < n; j++, x += 4) {
			curr += x * x * row[j];
		}
		for (int j = i - 1, x = 2; j >= 0; j--, x += 4) {
			curr += x * x * row[j];
		}
		if (curr < min_row) {
			ans_row = i;
			min_row = curr;
		}
	}
	ll min_col = 1e18;
	int ans_col;
	loop(i, 0, m) {
		ll curr = 0;
		for (int j = i, y = 2; j < m; j++, y += 4) {
			curr += (ll)y * y * col[j];
		}
		for (int j = i - 1, y = 2; j >= 0; j--, y += 4) {
			curr += (ll)y * y * col[j];
		}
		if (curr < min_col) {
			ans_col = i;
			min_col = curr;
		}
	}
	printf("%lld\n%d %d", min_col + min_row, ans_row, ans_col);
}