/*
	after tracing some test cases notice that we the edges that dont result in a cycle can be oriented in any way so 2^e
	for the edges that form a cycle along the path have 2^e - 2 number of ways because only 2 ways will form a cycle 
	(when all of them are oriented to the same direction or all of them are flipped)
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

int n;
int edges[N], vis[N],t[N];
int cnt;
ll ans = 1;

ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) % mod * a) % mod;
	return (res*res) % mod;
}

void dfs(int u,int e) {
	if (vis[u] == 1) {
		ll m = ((fastPower(2, e - edges[u]) + mod - 2) + mod) % mod;
		ans = (ans * m) % mod;
		cnt += e - edges[u];
		return;
	}
	edges[u] = e;
	vis[u] = 1;
	if (vis[t[u]] != 2 || !vis[t[u]])
		dfs(t[u], e + 1);
	vis[u] = 2;
}

int main() {
	scanf("%d",&n);
	loop(i, 1, n) {
		scanf("%d",&t[i]);
	}
	loop(i, 1, n) {
		if(!vis[i]) dfs(i, 0);
	}
	ll m = fastPower(2, n - cnt);
	ans = (ans * m) % mod;
	printf("%lld",ans);
}