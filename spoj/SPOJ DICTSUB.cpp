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

int n;
string s;
vector<int> v[26];

int main() {
	io;
	int t;
	cin >> t;
	while (t--) {
		loop(i, 0, 25)
			v[i].clear();
		cin >> n >> s;
		loop(i, 0, s.size() - 1) {
			v[s[i] - 'A'].push_back(i);
		}
		loop(i, 0, n - 1) {
			string a;
			cin >> a;
			stringstream ss(a);
			int x, curr = -1;
			char c;
			bool yes = 1;
			while (ss >> x >> c){
				auto it = upper_bound(v[c - 'A'].begin(), v[c - 'A'].end(), curr);
				if (it == v[c - 'A'].end()) {
					yes = 0;
					break;
				}
				int idx = it - v[c - 'A'].begin();
				if (idx + x - 1 >= v[c - 'A'].size()) {
					yes = 0;
					break;
				}
				curr = v[c - 'A'][idx + x - 1];
			}
			if (yes) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}