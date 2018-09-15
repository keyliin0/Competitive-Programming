/*
	try all solutions and memo
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
int t[50], dp[50][50];

int solve(int i,int rem) {
	if (rem == 0 && i < n) return oo;
	if (i == n) return 0;
	int &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = oo;
	int curr = 0 , idx = 1;
	loop(j, i, n - 1) {
		curr += t[j] * idx;
		idx++;
		ret = min(ret, curr + solve(j + 1, rem - 1));
	}
	return ret;
}

void build(int i,int rem) {
	if (i == n) {
		if (rem != 0) {
			loop(j, 1, rem) {
				printf("0 ");
			}
		}
		return;
	}
	int curr = 0, idx = 1;
	loop(j, i, n - 1) {
		curr += t[j] * idx;
		idx++;
		if (solve(i, rem) == curr + solve(j + 1, rem - 1)) {
			printf("%d ",idx - 1);
			build(j + 1, rem - 1);
			return;
		}
	}
}

int main() {
	freopen("sms.in", "r", stdin);
	freopen("sms.out", "w", stdout);
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1) {
		scanf("%d",&t[i]);
	}
	memset(dp, -1, sizeof dp);
	//cout << solve(0, m);
	build(0, m);
}