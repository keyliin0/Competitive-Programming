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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

bool can_go[1005][1005][5]; // check if you can go from interger i to j (only if index of i is less than j)
int dp[1005];
int n, k;
int t[1005];

int solve(int i) {
	int &ret = dp[i];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = 1; j <= n; j++) {
		bool can = 1;
		for (int x = 0; x < k; x++)
			can &= can_go[i][j][x];
		if (can) ret = max(ret, 1 + solve(j));
	}
	return ret;
}

int main() {
	scanf("%d%d",&n,&k);
	loop(x, 0, k - 1) {
		loop(i, 0, n - 1) {
			scanf("%d", &t[i]);
			can_go[0][t[i]][x] = 1;
		}
		loop(i, 0, n - 1)
			loop(j, i + 1, n - 1)
				can_go[t[i]][t[j]][x] = 1; 
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(0);
	printf("%d",ans);
}