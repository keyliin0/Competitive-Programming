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
int row[1005], col[1005];

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 0, n)
		row[i] = col[i] = 1;
	loop(i, 0, m - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		row[x] = 0;
		col[y] = 0;
	}
	int ans = 0;
	if (n % 2 != 0 && (row[n / 2] || col[n / 2]))
		ans++;
	for (int i = 1; i < n / 2; i++) {
		ans += row[i] + col[i] + row[n - i - 1] + col[n - i - 1];
	}
	printf("%d",ans);
}