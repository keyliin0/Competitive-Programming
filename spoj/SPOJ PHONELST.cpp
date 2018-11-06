/*
	sort the strings and before inserting each one check if there exist a prefix of the current string
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
string s[10005];

void insert(string s) {
	int curr = 0;
	for (int i = 0; i < s.size(); i++) {
		if (v[curr][s[i] - '0'] == -1) {
			v[curr][s[i] - '0'] = v.size();
			v.push_back(vector<int>(10, -1));
			e.push_back(false);
		}
		curr = v[curr][s[i] - '0'];
	}
	e[curr] = true;
}

bool find(int u,int i,string s) {
	if (e[u]) return 0;
	if (i < s.size()) {
		if (v[u][s[i] - '0'] == -1) return 1;
		return find(v[u][s[i] - '0'], i + 1, s);
	}
	return 1;
}

int main() {
	io;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		e.clear();
		v.push_back(vector<int>(10, -1));
		e.push_back(false);
		bool yes = 1;
		loop(i, 0, n - 1)
			cin >> s[i];
		sort(s, s + n);
		loop(i, 0, n - 1) {
			yes &= find(0, 0, s[i]);
			insert(s[i]);
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
}
