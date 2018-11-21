/*
	dp + probability
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

int n, k;
double p[1005],dp[1005][1005];
bool vis[1005][1005];
double perc;

ll calc(ull l,ull r) {
	string st = to_string(l);
	ull res = 0;
	ull s = 1;
	for (int i = 0; i < st.size() - 1; i++)
		s *= 10;
	if (st[0] != '1') s *= 10;
	while (s <= r) {
		res += min(r, 2 * s - 1) - max(s, l) + 1;
		s *= 10;
	}
	return res;
}

double solve(int i,int take) {
	if (i == n) {
		if (take >= perc) return 1.0;
		else return 0.0;
	}
	if (vis[i][take]) return dp[i][take];
	vis[i][take] = 1;
	double ret = 0;
	ret = p[i] * solve(i + 1, take + 1) + (1 - p[i]) * solve(i + 1, take);
	return dp[i][take] = ret;
}

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		ll l, r;
		scanf("%lld%lld",&l,&r);
		p[i] = (double)calc(l, r) / (r - l + 1.0);
		//printf("%.3lf ",p[i]);
	}
	scanf("%d",&k);
	perc = (double)(n * k) / 100.0;
	double ans = solve(0, 0);
	printf("%.9lf", ans);
}