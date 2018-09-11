/*
	got wa but code passes udebug test cases
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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
ll t[100005][10];
map<pair<int, int>, int> mp;
hash<string> h;

int main() {
	while (cin >> n >> m) {
		cin.ignore();
		loop(i, 0, n - 1) {
			string line;
			getline(cin, line);
			istringstream iss(line);
			string s, tmp = "";
			int j = 0;
			while (iss >> s) {
				if (s[s.size() - 1] == ',') {
					s.pop_back();
					tmp += s;
					t[i][j] = h(tmp);
					j++;
					tmp = "";
				}
				else {
					if (tmp != "") tmp += " ";
					tmp += s;
				}
			}
			t[i][j] = h(tmp);
		}
		bool ans = 0;
		int r1, r2, c1, c2;
		loop(i, 0, n - 1) {
			if (ans) break;
			loop(j, 0, m - 1) {
				if (ans) break;
				loop(k, j + 1, m - 1) {
					if (!mp[{t[i][j], t[i][k]}]) {
						mp[{t[i][j], t[i][k]}] = i + 1;
					}
					else {
						r1 = mp[{t[i][j], t[i][k]}];
						c1 = j + 1;
						r2 = i + 1;
						c2 = k + 1;
						ans = 1;
						break;
					}
				}
			}
		}
		if (ans) printf("NO\n%d %d\n%d %d", r1, r2, c1, c2);
		else printf("YES\n");
	}
}