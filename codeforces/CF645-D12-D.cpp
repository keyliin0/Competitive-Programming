/*
	use topological sort for ordering
	and binary search for the number of infos needed
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
map<string, int> mp;
vector<vector<int> > g;
int in[1005];
string s[1005];

int main() {
	io;
	int cas = 0;
	while (cin >> n) {
		g.clear();
		g.resize(n + 1);
		mp.clear();
		loop(i, 0, n - 1) {
			cin >> s[i];
			mp[s[i]] = i;
		}
		cin >> m;
		memset(in, 0, sizeof in);
		loop(i, 0, m - 1) {
			string a, b;
			cin >> a >> b;
			g[mp[a]].push_back(mp[b]);
			in[mp[b]]++;
		}
		priority_queue<int> q;
		loop(i, 0, n - 1) {
			sort(g[i].begin(), g[i].end());
			if (in[i] == 0) q.push(-i);
		}
		cout << "Case #" << ++cas << ": Dilbert should drink beverages in this order:";
		while (!q.empty()) {
			int u = -q.top();
			cout << " " << s[u];
			q.pop();
			for (int i = 0; i < g[u].size(); i++) {
				in[g[u][i]]--;
				if (in[g[u][i]] == 0) q.push(-g[u][i]);
			}
		}
		cout << "." << endl << endl;
	}
}