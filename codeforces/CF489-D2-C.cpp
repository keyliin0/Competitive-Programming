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

int n, s;
int dp1[101][905][2], dp2[101][905][2];

int solve1(int i,int s,bool t) {
	if (s < 0) return 0;
	if (i == n) return s == 0;
	int &ret = dp1[i][s][t];
	if (ret != -1) return ret;
	ret = 0;
	if (t) ret = solve1(i + 1, s, t);
	for (int j = 1; j < 10 && !ret; j++)
		ret = solve1(i + 1, s - j, 1);
	return ret;
}

void build1(int i, int s, bool t) {
	if (s < 0) return;
	if (i == n) return;
	if (t && solve1(i, s, t) == solve1(i + 1, s, t)) {
		printf("0");
		build1(i + 1, s, t);
		return;
	}
	for (int j = 1; j < 10; j++)
		if (solve1(i, s, t) == solve1(i + 1, s - j, 1)) {
			printf("%d",j);
			build1(i + 1, s - j, 1);
			return;
		}
}

int solve2(int i, int s, bool t) {
	if (s < 0) return 0;
	if (i == n) return s == 0;
	int &ret = dp2[i][s][t];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = 9; j >= 0 && !ret; j--)
		ret = solve2(i + 1, s - j, 1);
	if (t) ret = solve2(i + 1, s, t);
	return ret;
}

void build2(int i, int s, bool t) {
	if (s < 0) return;
	if (i == n) return;
	for (int j = 9; j >= 1; j--)
		if (solve1(i, s, t) == solve1(i + 1, s - j, 1)) {
			printf("%d", j);
			build2(i + 1, s - j, 1);
			return;
		}
	if (t && solve2(i, s, t) == solve2(i + 1, s, t)) {
		printf("0");
		build2(i + 1, s, t);
		return;
	}
}

int main() {
	scanf("%d%d",&n,&s);
	if (n == 1 && s == 0) {
		printf("0 0");
		return 0;
	}
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	int a1 = solve1(0, s, 0);
	int a2 = solve2(0, s, 0);
	if (a1 == 0) {
		printf("-1 -1");
		return 0;
	}
	build1(0, s, 0);
	printf(" ");
	build2(0, s, 0);
}