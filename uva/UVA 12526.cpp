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
vector<vector<int> > freq;
string b;
int cnt;
int ans;

void insert(string s) {
	int curr = 0;
	for (int i = 0; i < s.size(); i++) {
		if (v[curr][s[i] - 'a'] == -1) {
			v[curr][s[i] - 'a'] = v.size();
			v.push_back(vector<int>(26, -1));
			freq.push_back(vector<int>(26, 0));
			e.push_back(false);
		}
		freq[curr][s[i] - 'a']++;
		curr = v[curr][s[i] - 'a'];
	}
	e[curr] = true;
}

void dfs(int u) {
	int cnt = 0, cnt2 = 0;
	for (int i = 0; i < 26; i++) {
		if (v[u][i] != -1) {
			cnt += freq[u][i];
			cnt2++;
			dfs(v[u][i]);
		}
	}
	if (cnt2 == 1) {
		if (e[u]) ans += cnt;
	}
	else ans += cnt;
}

int main() {
	io;
	while (cin >> n) {
		v.clear();
		freq.clear();
		e.clear();
		v.push_back(vector<int>(26, -1));
		freq.push_back(vector<int>(26, 0));
		e.push_back(false);
		loop(i, 0, n - 1) {
			string s;
			cin >> s;
			insert(s);
		}
		ans = 0;
		loop(i, 0, 25) {
			if (v[0][i] != -1) {
				ans += freq[0][i];
				dfs(v[0][i]);
			}
		}
		cout << fixed << setprecision(2) <<  (double)ans / n  << "\n";
	}
}