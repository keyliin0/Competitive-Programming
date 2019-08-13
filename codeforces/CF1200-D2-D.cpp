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
 
int n, k;
char g[2005][2005];
int row_pre[2005][2005], col_pre[2005][2002];
int sum_row[2005], sum_col[2005];
int acc[2005][2005];
 
int main() {
	scanf("%d%d", &n, &k);
	loop(i, 0, n - 1)
		scanf("%s", g[i]);
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) {
			if (j) row_pre[i][j] += row_pre[i][j - 1];
			if (g[i][j] == 'B') row_pre[i][j]++;
		}
	}
	loop(j, 0, n - 1) {
		loop(i, 0, n - 1) {
			if (i) col_pre[i][j] += col_pre[i - 1][j];
			if (g[i][j] == 'B') col_pre[i][j]++;
		}
	}
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) {
			if (g[i][j] == 'B') {
				sum_row[i]++;
				sum_col[j]++;
			}
		}
	}
	int ans = 0;
	loop(i, 0, n - 1)
		ans += (sum_row[i] == 0) + (sum_col[i] == 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + k - 1 < n; j++) {
			if (i) acc[i][j] += acc[i - 1][j];
			if (sum_row[i] == 0) continue;
			int sum = row_pre[i][j + k - 1] - (j ? row_pre[i][j - 1] : 0);
			if (sum == sum_row[i]) acc[i][j]++;
		}
	}
	int mx = 0;
	for (int i = 0; i + k - 1 < n; i++) {
		int curr_col = 0;
		for (int j = 0; j < k; j++) {
			if (sum_col[j] == 0) continue;
			if (sum_col[j] == (col_pre[i + k - 1][j] - (i ? col_pre[i - 1][j] : 0)))
				curr_col++;
		}
		mx = max(mx, curr_col + acc[i + k - 1][0] - (i ? acc[i - 1][0] : 0));
		for (int j = k; j < n; j++) {
			if (sum_col[j - k] != 0 && sum_col[j - k] == (col_pre[i + k - 1][j - k] - (i ? col_pre[i - 1][j - k] : 0)))
				curr_col--;
			if (sum_col[j] != 0 && sum_col[j] == (col_pre[i + k - 1][j] - (i ? col_pre[i - 1][j] : 0)))
				curr_col++;
			mx = max(mx, curr_col + acc[i + k - 1][j - k + 1] - (i ? acc[i - 1][j - k + 1] : 0));
		}
	}
	printf("%d",ans + mx);
}