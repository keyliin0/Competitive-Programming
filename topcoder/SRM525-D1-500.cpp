/*
	use mask 
	if ith bit = 0 then node i must share first rumor first then the second 
	otherwise the second then the first
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

string s;
vector<vector<int> > g;
int n;

class Rumor {
public:
	int calc(int mask) {
		queue<pair<int, pair<int,int> > > q;
		int v[30][2];
		for (int i = 0; i < n; i++) {
			if (s[i] == 'Y') {
				v[i][0] = v[i][1] = 0;
				int x = ((1 << i) & mask) ? 1 : 0;
				for (int j = 0; j < g[i].size(); j++) {
					q.push({ g[i][j],{1,x} });
					q.push({ g[i][j],{2,!x} });
				}
			}
			else v[i][0] = v[i][1] = oo;
		}
		while (!q.empty()) {
			int u = q.front().first;
			int d = q.front().second.first;
			int r = q.front().second.second;
			q.pop();
			if (v[u][r] <= d) continue;
			v[u][r] = d;
			int x = ((1 << u) & mask) ? 1 : 0;
			for (int i = 0; i < g[u].size(); i++) {
				if (v[u][x] != oo && v[u][!x] != oo) {
					q.push({ g[u][i],{v[u][x] + 1,x} });
					q.push({ g[u][i],{max(v[u][x] + 2,v[u][!x] + 1),!x} });
				}
			}
		}
		int mx = -1;
		for (int i = 0; i < n; i++) {
			mx = max({ mx,v[i][0],v[i][1] });
		}
		return mx;
	}
	int getMinimum(string knowledge, vector <string> graph) {
		n = knowledge.size();
		s = knowledge;
		g.resize(n + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == 'Y')
					g[i].push_back(j);
			}
		}
		int ans = oo;
		for (int i = 0; i < (1 << n); i++) {
			ans = min(ans, calc(i));
		}
		return ans == oo ? -1 : ans;
	}
};
