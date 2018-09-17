/*
	build a graph of 2 * n nodes (each node have it's own complement)
	if t = 1 put connect node a with b and the complement of a with the complement of b
	otherwise connect the node a with the complement of b and the complement of a with b
	answering queries : 
	if a and b are connected then the type of relation is 1
	if a and complement of b are connected then the type of the relation is 2
	otherwise the answer is 3
	
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

map<string, int> id;
int p[N];
int n, m, q;

int find(int u) {
	if (p[u] == u)
		return u;
	return p[u] = find(p[u]);
}

int main() {
	io;
	cin >> n >> m >> q;
	loop(i, 0, n - 1) {
		string s;
		cin >> s;
		id[s] = i + 1;
	}
	loop(i, 1, 2 * n) {
		p[i] = i;
	}
	loop(i, 0, m - 1) {
		int t;
		string s1, s2;
		cin >> t >> s1 >> s2;
		int x1 = id[s1];
		int x2 = id[s2];
		int a = find(x1);
		int b = find(x2);
		int a1 = find(x1 + n);
		int b1 = find(x2 + n);
		if (t == 1 && (b == a1 || a == b1)) {
			cout << "NO" << endl;
			continue;
		}
		if (t == 2 && (b == a || a1 == b1)) {
			cout << "NO" << endl;
			continue;
		}
		if (t == 1) {
			p[a] = b;
			p[a1] = b1;
		}
		else {
			p[a] = b1;
			p[a1] = b;
		}
		cout << "YES" << endl;
	}
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int x1 = id[s1];
		int x2 = id[s2];
		int a = find(x1);
		int b = find(x2);
		int a1 = find(x1 + n);
		int b1 = find(x2 + n);
		if (a == b) {
			cout << "1" << endl;
		}
		else if (a1 == b) cout << "2" << endl;
		else cout << "3" << endl;
	}
}