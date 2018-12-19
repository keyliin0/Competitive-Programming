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

ll adj[205][205], cst[205][205];
map<string, int> mp;
string city[205];
string route[205][205];
int pre[205][205];

void prt(int i,int j) {
	if (i == j) return;
	prt(i, pre[i][j]);
	printf("%-20s %-20s %-10s %5lld\n", city[pre[i][j]].c_str(), city[j].c_str(), route[pre[i][j]][j].c_str(), cst[pre[i][j]][j]);
}


int main() {
	loop(i, 1, 200) {
		loop(j, 1, 200) {
			adj[i][j] = oo;
			pre[i][j] = i;
		}
	}
	string line;
	int n = 0;
	while (getline(cin, line)) {
		if (line == "")
			break;
		string s = "";
		vector<string> v;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ',') {
				v.push_back(s);
				s = "";
				continue;
			}
			s += line[i];
		}
		v.push_back(s);
		if (mp[v[0]] == 0) {
			mp[v[0]] = ++n;
			city[n] = v[0];
		}
		if (mp[v[1]] == 0) {
			mp[v[1]] = ++n;
			city[n] = v[1];
		}
		if (stoi(v[3]) < adj[mp[v[0]]][mp[v[1]]]) {
			adj[mp[v[0]]][mp[v[1]]] = adj[mp[v[1]]][mp[v[0]]] = cst[mp[v[0]]][mp[v[1]]] = cst[mp[v[1]]][mp[v[0]]] = stoi(v[3]);
			route[mp[v[0]]][mp[v[1]]] = route[mp[v[1]]][mp[v[0]]] = v[2];
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					pre[i][j] = pre[k][j];
				}
			}
	while (getline(cin, line)) {
		if (line == "")
			break;
		string s = "";
		vector<string> v;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ',') {
				v.push_back(s);
				s = "";
				continue;
			}
			s += line[i];
		}
		v.push_back(s);
		cout << endl << endl;
		cout << "From                 To                   Route      Miles" << endl;
		cout << "-------------------- -------------------- ---------- -----" << endl;
		prt(mp[v[0]], mp[v[1]]);
		cout << "                                                     -----" << endl;
		printf("                                          Total      %5lld\n", adj[mp[v[0]]][mp[v[1]]]);
	}
}