/*
	use dp to store the probability of the i-th team winning in the k-th round
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

string t[16];
double p[16][16];
double dp[16][5];

void solve(int l,int r,int k) {
	if (l == r) {
		dp[l][k] = 1;
		return;
	}
	solve(l, (l + r) / 2, k - 1);
	solve((l + r) / 2 + 1, r, k - 1);
	for (int i = l; i <= (l + r) / 2; i++) {
		for (int j = (l + r) / 2 + 1; j <= r; j++) {
			dp[i][k] += dp[i][k - 1] * dp[j][k - 1] * (p[i][j] / 100.0);
			dp[j][k] += dp[i][k - 1] * dp[j][k - 1] * (p[j][i] / 100.0);
		}
	}
}

int main() {
	loop(i, 0, 15)
		cin >> t[i];
	loop(i, 0, 15)
		loop(j, 0, 15)
			cin >> p[i][j];
	solve(0, 15, 4);
	loop(i, 0, 15) {
		printf("%-10s p=%.2lf%%\n", t[i].c_str(), dp[i][4] * 100.0);
	}
}