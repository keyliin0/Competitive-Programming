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

int dp[51][52][2005][2];
int n, s, k;
pair<int,int> t[55];
int R[55];
char c[55];

// current index - last position - rem - 1 if already took at least 1 box

int solve(int i,int last,int rem,bool f) {
	if (rem <= 0) return 0;
	if (i > n) return oo;
	int &ret = dp[i][last][rem][f];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, solve(i + 1, last, rem, f));
	if (!f) ret = min(ret, abs(last - t[i].second) + solve(i + 1, t[i].second, rem - t[i].first, 1));
	else if (c[last - 1] != c[t[i].second - 1] && R[t[i].second] > R[last]) ret = min(ret, abs(last - t[i].second) + solve(i + 1, t[i].second, rem - t[i].first, f));
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &s, &k);
	loop(i, 1, n) {
		scanf("%d", &R[i]);
		t[i].first = R[i];
		t[i].second = i;
	}
	scanf("%s",c);
	sort(t + 1, t + n + 1);
	memset(dp, -1, sizeof dp);
	int ans = solve(1, s, k, 0);
	printf("%d", (ans == oo ? -1 : ans));
}