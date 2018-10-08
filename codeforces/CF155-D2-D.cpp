/*
	precalculate the divisors for each number
	for each number check if there is a number that have the same divisor and is on
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

int n, m, on[N];
set<int> s[N];
vector<int> v[N];

int main() {
	io;
	cin >> n >> m;
	v[1].push_back(1);
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				v[i].push_back(j);
				if(i / j != j) v[i].push_back(i / j);
			}
		}
		v[i].push_back(i);
	}
	while (m--) {
		char c;
		int a;
		cin >> c >> a;
		if (c == '+' && on[a]) {
			cout << "Already on" << endl;
			continue;
		}
		if (c == '-' && !on[a]) {
			cout << "Already off" << endl;
			continue;
		}
		if (c == '-') {
			on[a] = 0;
			for (int i = 0; i < v[a].size(); i++)
				s[v[a][i]].erase(s[v[a][i]].find(a));
		}
		if (c == '+') {
			int x = -1;
			for (int i = 0; i < v[a].size() && x == -1; i++)
				if(s[v[a][i]].size()) x = *s[v[a][i]].begin();
			if (x != -1) {
				cout << "Conflict with " << x << endl;
				continue;
			}
			on[a] = 1;
			for (int i = 0; i < v[a].size(); i++) {
				s[v[a][i]].insert(a);
			}
		}
		cout << "Success" << endl;
	}
}