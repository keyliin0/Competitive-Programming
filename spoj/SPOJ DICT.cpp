/*
	use trie and dfs
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

int n, q;
vector<vector<int> > v;
vector<bool> e;
string b;
int cnt;

void insert(string s) {
	int curr = 0;
	for (int i = 0; i < s.size(); i++) {
		if (v[curr][s[i] - 'a'] == -1) {
			v[curr][s[i] - 'a'] = v.size();
			v.push_back(vector<int>(26, -1));
			e.push_back(false);
		}
		curr = v[curr][s[i] - 'a'];
	}
	e[curr] = true;
}

void find(int u, int i, string s = "") {
	if (i < b.size()) {
		if (v[u][b[i] - 'a'] == -1) return;
		find(v[u][b[i] - 'a'], i + 1, s + b[i]);
	}
	else {
		if (s != b && e[u]) cout << s << "\n", cnt++;
		for (int j = 0; j < 26; j++) {
			if (v[u][j] != -1) find(v[u][j], i + 1, s + char(j + 'a'));
		}
	}
}

int main() {
	io;
	cin >> n;
	v.push_back(vector<int>(26, -1));
	e.push_back(false);
	loop(i, 0, n - 1) {
		string s;
		cin >> s;
		insert(s);
	}
	cin >> q;
	loop(i, 1, q) {
		cin >> b;
		cout << "Case #" << i << ":\n";
		cnt = 0;
		find(0, 0);
		if (cnt == 0) cout << "No match.";
		cout << "\n";
	}
}
