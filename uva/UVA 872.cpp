/* 
	we try every possible solution
	an output is invalid if we visit B before A and A < B
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int tests;
bool edge[30][30];
bool vis[30];
vector<char> v;
bool ok;

void solve(string curr) {
	bool done = 1;
	for (int i = 0; i < v.size(); i++) {
		bool valid = 1;
		if (vis[i]) continue;
		done = 0;
		for (int j = 0; j < v.size(); j++) {
			if (vis[j] && edge[v[i]-'A'][v[j]-'A']) valid = 0;
		}
		if (valid) {
			vis[i] = 1;
			solve(curr + v[i]);
			vis[i] = 0;
		}
	}
	if (done) {
		ok = 1;
		for (int i = 0; i < curr.size(); i++) {
			if (i) cout << " ";
			cout << curr[i];
		}
	}
}

int main() {
	cin >> tests;    
	cin.ignore();
	while (tests--) {
		string line;
		cin.ignore();
		getline(cin, line);
		v.clear();
		memset(edge, 0, sizeof edge);
		for (int i = 0; i < line.size(); i++)
			if (line[i] != ' ') v.push_back(line[i]);
		sort(v.begin(), v.end());
		getline(cin, line);
		for (int i = 0; i < line.size(); i += 4) {
			edge[line[i] - 'A'][line[i + 2] - 'A'] = 1;
		}
		ok = 0;
		solve("");
		if (!ok) cout << "NO" << endl;
	}
}