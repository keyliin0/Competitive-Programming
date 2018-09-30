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

vector<pair<int, int> > p;
vector<int> v;
map<int, int> mp;
int in[N];
vector<vector<int> > g;
bool yes;
bool vis[N];

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		if (vis[g[u][i]]) {
			yes = 0;
			return;
		}
		dfs(g[u][i]);
	}
}

int main() {
	int cas = 0;
	while (1) {
		cas++;
		yes = 1;
		p.clear();
		v.clear();
		mp.clear();
		int a, b;
		while (scanf("%d%d", &a, &b)) {
			if (a < 0 && b < 0) return 0;
			if (a == 0 && b == 0) break;
			p.push_back({ a,b });
			v.push_back(a);
			v.push_back(b);
			if (a == b) yes = 0;
		}
		printf("Case %d ",cas);
		if (v.size() == 0) {
			printf("is a tree.\n");
			continue;
		}
		sort(v.begin(), v.end());
		mp[v[0]] = 1;
		int cnt = 2;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == v[i - 1]) continue;
			mp[v[i]] = cnt++;
		}
		g.clear();
		g.resize(cnt + 1);
		memset(in, 0, sizeof in);
		for (int i = 0; i < p.size(); i++) {
			g[mp[p[i].first]].push_back(mp[p[i].second]);
			in[mp[p[i].second]]++;
		}
		int start = -1;
		loop(i, 1, cnt - 1) {
			if (in[i] == 0) {
				if (start != -1) yes = 0;
				start = i;
			}
			if (in[i] > 1) yes = 0;
		}
		if (!yes || start == -1 || p.size() != cnt - 2) {
			printf("is not a tree.\n");
			continue;
		}
		memset(vis, 0, sizeof vis);
		dfs(start);
		loop(i,1,cnt - 1){
			if (!vis[i]) yes = 0;
		}
		if (yes) printf("is a tree.\n");
		else printf("is not a tree.\n");
	}
}