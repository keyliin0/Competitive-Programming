/*
	keep a stack of nodes that are currently being visited 
	if a node have an adj node which is in the stack the there is a cycle 
	add +1 to all these nodes with the help of the stack 
	if any node is included in more than one cycle then dont count its comp
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define sz(v)   ((int)(v).size())


vector<vector<int> > g;
int vis[205];
int cnt[205];
bool ok;
vector<int> st;

class CactusCount {
public:
	void dfs(int u,int p) {
		st.push_back(u);
		vis[u] = 1;
		for (auto v : g[u]) {
			if (v == p) continue;
			if (!vis[v]) {
				dfs(v, u);
			}
			else if(vis[v] == 1){
				cnt[v]++;
				if (cnt[v] == 2) ok = 0;
				for (int i = st.size() - 1; i >= 0 && st[i] != v; i--) {
					cnt[st[i]]++;
					if (cnt[st[i]] == 2) ok = 0;
				}
			}
		}
		vis[u] = 2;
		st.pop_back();
	}
	int countCacti(int n, vector <string> vv) {
		g.resize(n + 1);
		/* parsing part copied from 
		https://github.com/BRAINOOOO/CompetitiveProgramming/blob/master/Topcoder/SRM419-D2-1000.Cpp */
		string s = "";
		for (int i = 0; i < sz(vv); i++)
			s += vv[i];
		s += ',';
		string st = "";
		int fr = 0, to = 0;
		for (int i = 0; i < sz(s) && sz(s)>1; i++){
			if (isdigit(s[i]))
				st += s[i];
			if (s[i] == ' ')
			{
				fr = atoi(st.c_str());

				st = "";
			}

			if (s[i] == ',')
			{
				to = atoi(st.c_str());

				g[fr].push_back(to);

				g[to].push_back(fr);
				st = "";
			}
		}
		int ans = 0;
		loop(i, 1, n) {
			if (!vis[i]) {
				ok = 1;
				dfs(i, -1);
				if (ok) ans++;
			}
		}
		return ans;
	}
};