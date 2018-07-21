#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, h;
int d[30], t[30], f[30];
int dp[30][200][200];
int path[30];

int calc(int i,int rem,int take) {
	if (rem < 0) return -oo;
	if (i == n || rem == 0) return 0;
	int &ret = dp[i][rem][take];
	if (ret != -1) return ret;
	ret = -oo;
	ret = max(ret, (f[i] - take * d[i] > 0 ? f[i] - take * d[i] : 0) + calc(i, rem - 1, take + 1));
	ret = max(ret, calc(i + 1, rem - t[i], 0));
	return ret;

}

void build(int i, int rem, int take) {
	if (i == n || rem <= 0) return;
	if (calc(i, rem, take) == (f[i] - take * d[i] > 0 ? f[i] - take * d[i] : 0) + calc(i, rem - 1, take + 1)) {
		path[i]++;
		build(i, rem - 1, take + 1);
		return;
	}
	else {
		build(i + 1, rem - t[i], 0);
		return;
	}
}

int main() {
	bool newline = 0;
	while (1) {
		if (newline) printf("\n");
		scanf("%d",&n);
		if (n == 0) break;
		scanf("%d",&h);
		loop(i, 0, n - 1)
			scanf("%d", &f[i]);
		loop(i, 0, n - 1)
			scanf("%d", &d[i]);
		loop(i, 0, n - 2)
			scanf("%d", &t[i]);
		memset(dp, -1, sizeof dp);
		memset(path, 0, sizeof path);
		int ans = calc(0, h * 60 / 5,0);
		build(0, h * 60 / 5, 0);
		loop(i, 0, n - 1) {
			if (i > 0) printf(", ");
			printf("%d", path[i] * 5);
		}
		printf("\nNumber of fish expected: %d\n", ans);
		newline = 1;
	}
}
