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
pair<int, int> t[N];
ll dp[N],sum[N];
vector<int> all;
map<int, int> mp;


bool compare(pair<int,int> &i, pair<int, int> &j) {
	return i.second < j.second;
}

int main() {
	scanf("%d%d", &n, &m);
	all.push_back(n);
	all.push_back(0);
	loop(i, 0, m - 1) {
		scanf("%d%d", &t[i].first, &t[i].second);
		all.push_back(t[i].first);
		all.push_back(t[i].second);
	}
	sort(all.begin(), all.end());
	mp[0] = 0;
	int cnt = 1;
	// -- compression
	loop(i, 1, all.size() - 1) {
		if (all[i - 1] != all[i]) {
			mp[all[i]] = cnt;
			cnt++;
		}
	}
	loop(i, 0, m - 1) {
		t[i].first = mp[t[i].first];
		t[i].second = mp[t[i].second];
	}
	sort(t, t + m, compare);
	n = mp[n];
	dp[0] = 1;
	int r = 0;
	loop(i, 0, n) {
		while (r < m && t[r].second == i) { // number of ways to reach ith point += sum number of ways to reach all point start <= i < end
			dp[i] = (dp[i] + ((sum[i] - sum[t[r].first] + mod) % mod)) % mod;
			r++;
		}
		sum[i + 1] = (sum[i] + dp[i]) % mod;
	}
	printf("%lld",dp[n]);
}