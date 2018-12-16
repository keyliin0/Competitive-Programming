/*
	for each array we calculate it's maximum prefix , suffix , and middle sum 
	if the answer is in a single array then the answer is the maximum middle sum 
	otherwise in general the best answer is : 
	the max suffix sum of the first array + whole sum of arrays in the middle + max prefix sum of the last array 
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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
vector<ll> t[51];
int arr[N];
ll pre[51], suff[51], mx[51], sum[51];
ll dp[N][2];

ll solve(int i,bool take) {
	if (i == m) return take ? 0 : -1e18;
	ll &ret = dp[i][take];
	if (ret != -1e18) return ret;
	if (!take) {
		ret = mx[arr[i]];
		ret = max(ret, solve(i + 1, 0));
		ret = max(ret, suff[arr[i]] + solve(i + 1, 1));
	}
	else {
		ret = pre[arr[i]];
		ret = max(ret, sum[arr[i]] + solve(i + 1, 1));
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 0, n - 1) {
		int l;
		scanf("%d",&l);
		ll all = 0;
		loop(j, 0, l - 1) {
			ll x;
			scanf("%lld",&x);
			t[i].push_back(x);
			all += x;
		}
		sum[i] = all;
	}
	loop(i, 0, m - 1) {
		scanf("%d", &arr[i]);
		arr[i]--;
		dp[i][0] = dp[i][1] = -1e18;
	}
	loop(i, 0, n - 1) {
		pre[i] = t[i][0];
		suff[i] = t[i][t[i].size() - 1];
		ll curr = 0;
		for (int j = 0; j < t[i].size(); j++) {
			curr += t[i][j];
			pre[i] = max(pre[i], curr);
		}
		curr = 0;
		for (int j = t[i].size() - 1; j >= 0; j--) {
			curr += t[i][j];
			suff[i] = max(suff[i], curr);
		}
		ll dp2[5001];
		dp2[0] = curr = t[i][0];
		for (int j = 1; j < t[i].size(); j++) {
			dp2[j] = max(t[i][j], dp2[j - 1] + t[i][j]);
			curr = max(curr, dp2[j]);
		}
		mx[i] = curr;
	}
	ll ans = solve(0, 0);
	printf("%lld",ans);
}