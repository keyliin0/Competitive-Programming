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
 
int l[N], r[N];
int n, m, k, q;
int pre[N],suf[N];
map<pair<int, int>, ll> dp;
int mx_row = 0;
 
ll left(int row,int col) {
	return abs(r[row] - 1LL * col) + abs(r[row] - l[row]);
}
 
ll right(int row, int col) {
	return abs(l[row] - 1LL * col) + abs(r[row] - l[row]);
}
 
ll solve(int row,int col) {
	if (row == mx_row) return min(left(row, col), right(row, col));
	if (dp.count({ row,col })) return dp[{row, col}];
	ll &ret = dp[{row,col}];
	ret = 1e18;
	if (l[row]) {
		if (pre[l[row]]) ret = min(ret, left(row, col) + 1LL * abs(pre[l[row]] - l[row]) + solve(row + 1, pre[l[row]]) + 1);
		if (suf[l[row]]) ret = min(ret, left(row, col) + 1LL * abs(suf[l[row]] - l[row]) + solve(row + 1, suf[l[row]]) + 1);
		if (pre[r[row]]) ret = min(ret, right(row, col) + 1LL * abs(pre[r[row]] - r[row]) + solve(row + 1, pre[r[row]]) + 1);
		if (suf[r[row]]) ret = min(ret, right(row, col) + 1LL * abs(suf[r[row]] - r[row]) + solve(row + 1, suf[r[row]]) + 1);
	}
	else {
		if (pre[col]) ret = min(ret, abs(pre[col] - col) + solve(row + 1, pre[col]) + 1);
		if (suf[col]) ret = min(ret, abs(suf[col] - col) + solve(row + 1, suf[col]) + 1);
	}
	return ret;
}
 
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	loop(i, 0, k - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (l[x] == 0) l[x] = y;
		if (r[x] == 0) r[x] = y;
		l[x] = min(l[x], y);
		r[x] = max(r[x], y);
		mx_row = max(mx_row, x);
	}
	loop(i, 0, q - 1) {
		int x;
		scanf("%d", &x);
		pre[x] = x;
		suf[x] = x;
	}
	loop(i, 1, m) {
		if (pre[i] == 0) pre[i] = pre[i - 1];
	}
	loop2(i, m, 1)
		if (suf[i] == 0) suf[i] = suf[i + 1];
 
	cout << solve(1, 1);
}