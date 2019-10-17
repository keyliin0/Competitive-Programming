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

int n;
string t[105];
vector<vector<int> > g(26);
bool edge[26][26];
int vis[26];
int in[55];
bool f;

void dfs(int u) {
	if (vis[u] == 2) {
		return;
	}
	if (vis[u] == 1) {
		f = 1;
		return;
	}
	vis[u] = 1;
	for (auto v : g[u]) {
		dfs(v);
	}
	vis[u] = 2;
}

int main() {
	io;
	cin >> n;
	loop(i, 0, n - 1)
		cin >> t[i];
	loop(i, 0, n - 2) {
		string &a = t[i];
			string &b = t[i + 1];
			int cnt = 0;
			while (cnt < a.size() && cnt < b.size()) {
				if (b[cnt] - 'a' != a[cnt] - 'a') {
					if (!edge[a[cnt] - 'a'][b[cnt] - 'a']) {
						g[a[cnt] - 'a'].push_back(b[cnt] - 'a');
						edge[a[cnt] - 'a'][b[cnt] - 'a'] = 1;
						in[b[cnt] - 'a']++;
					}
					break;
				}
				cnt++;
			}
			if ((cnt == a.size() || cnt == b.size()) && a.size() > b.size()) {
				cout << "Impossible";
				return 0;
			}
		
	}
	loop(i, 0, 25)
		if (!vis[i]) dfs(i);
	if (f) {
		cout << "Impossible";
		return 0;
	}
	queue<int> q;
	loop(i, 0, 25)
		if (in[i] == 0)
			q.push(i);
	vector<char> ans;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans.push_back((char) 'a' + u);
		for (auto v : g[u]) {
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	loop(i, 0, 25)
		cout << ans[i];
}