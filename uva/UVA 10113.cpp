/*
	represent relations as a graph 
	if a s1 = b s2 then there is an edge from s1 to s2 equals  a / b and from s2 to s1 equals b / a
	the result is the multiplication of all weights from source to destination
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

vector<pair<int,pair<ll,ll> > >  g[100005];
map<string, int> mp;
ll ans1, ans2;
bool found = 0;
bool vis[100005];

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

void dfs(int u,int dest,ll a,ll b) {
	ll gg = GCD(a, b);
	a /= gg;
	b /= gg;
	if (dest == u) {
		ans1 = a;
		ans2 = b;
		found = 1;
		return;
	}
	vis[u] = 1;
	for (int i = 0; i < g[u].size() && !found; i++) {
		if (!vis[g[u][i].first]) {
			dfs(g[u][i].first, dest, a * g[u][i].second.first, b * g[u][i].second.second);
		}
	}
}

int main() {
	int cnt = 1;
	while (1) {
		char t;
		cin >> t;
		if (t == '.') return 0;
		if (t == '!') {
			ll a, b;
			char c;
			string s1, s2;
			cin >> a >> s1 >> c >> b >> s2;
			if (!mp[s1]) mp[s1] = cnt,cnt++;
			if (!mp[s2]) mp[s2] = cnt,cnt++;
			g[mp[s1]].push_back({ mp[s2] , {a , b} });
			g[mp[s2]].push_back({ mp[s1] , {b , a} });
		}
		else {
			char c;
			string s1, s2;
			cin >> s1 >> c >> s2;
			found = 0;
			memset(vis, 0, sizeof vis);
			dfs(mp[s1], mp[s2], 1, 1);
			if(!found) cout << "? " << s1 << " = ? " << s2 << "\n";
			else cout << ans1 << " " << s1 << " = " << ans2 << " " << s2 << "\n";
		}
	}
}