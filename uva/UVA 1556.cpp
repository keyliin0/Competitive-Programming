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
vector<map<string, int> > t;
vector<string> e;

void insert(vector<string> & v) {
	int curr = 0;
	for (int i = 0; i < v.size(); i++) {
		if (t[curr][v[i]]) {
			curr = t[curr][v[i]];
		}
		else {
			t[curr][v[i]] = t.size();
			curr = t.size();
			map<string, int> mp;
			t.push_back(mp);
			e.push_back(v[i]);
		}
	}
}

void dfs(int depth,int curr) {
	if (curr) {
		for (int i = 1; i < depth; i++)
			cout << " ";
		cout << e[curr] << "\n";
	}
	for (auto &it : t[curr]) {
		dfs(depth + 1, it.second);
	}
}


int main() {
	io;
	while (cin >> n) {
		t.clear();
		e.clear();
		map<string, int> mp;
		t.push_back(mp);
		e.push_back("");
		loop(i, 0, n - 1) {
			string s;
			cin >> s;
			vector<string> v;
			string tmp = "";
			loop(j, 0, s.size() - 1) {
				if (s[j] == '\\') {
					v.push_back(tmp);
					tmp = "";
				}
				else tmp += s[j];
			}
			v.push_back(tmp);
			insert(v);
		}
		dfs(0, 0);
		cout << "\n";
	}
}
