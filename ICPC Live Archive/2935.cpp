#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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
vector<vector<int> > g1,g2;
string s1, s2;

pair<vector<vector<int> >,int> build(string s) {
	vector<vector<int> > g;
	g.resize(s.size() + 3);
	stack<int> q;
	int n = 0;
	q.push(0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			int u = q.top();
			n++;
			g[u].push_back(n);
			g[n].push_back(u);
			q.push(n);
		}
		else q.pop();
	}
	return { g,n };
}

string get(int v,vector<vector<string> > sub) {
	string ret = "(";
	sort(sub[v].begin(), sub[v].end());
	for (int i = 0; i < sub[v].size(); i++) {
		ret += sub[v][i];
	}
	ret += ")";
	return ret;
}

string canonicalform(vector<vector<int> > g,int nodes) {
	queue<int> leaf;
	vector<int> deg(nodes, -1);
	for (int i = 0; i < nodes; i++)
		if (g[i].size() == 1) 
			leaf.push(i);
		else deg[i] = g[i].size();
	vector<vector<string> > sub(nodes);
	int rem = nodes;
	while (rem > 2) {
		int sz = leaf.size();
		while (sz--) {
			int v = leaf.front();
			leaf.pop();
			string rep = get(v, sub);
			for (int i = 0; i < g[v].size(); i++) {
				sub[g[v][i]].push_back(rep);
				if (--deg[g[v][i]] == 1)
					leaf.push(g[v][i]);
			}
			rem--;
		}
	}
	int v1 = leaf.front();
	leaf.pop();
	int v2 = leaf.empty() ? -1 : leaf.front();
	string s1 = get(v1, sub);
	string s2 = v2 == -1 ? "" : get(v2, sub);
	if (v2 == -1) return s1;
	sub[v1].push_back(s2);
	sub[v2].push_back(s1);
	return min(get(v1, sub), get(v2, sub));

}

int main() {
	io;
	int tests;
	cin >> tests;
	while (tests--) {
		cin >> s1 >> s2;
		g1.clear();
		g2.clear();
		g1.resize(s1.size() + 5);
		g2.resize(s2.size() + 5);
		pair<vector<vector<int> >, int> f1 = build(s1);
		pair<vector<vector<int> >, int> f2 = build(s2);
		g1 = f1.first;
		int nodes1 = f1.second + 1;
		g2 = f2.first;
		int nodes2 = f2.second + 1;
		string a = canonicalform(g1, nodes1);
		string b = canonicalform(g2, nodes2);
		if (a == b) cout << "same" << endl;
		else cout << "different" << endl;
	}
}