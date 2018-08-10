#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

string s;
int k;

int main() {
	cin >> s >> k;
	loop(i, 0, k - 1)
		s += '.';
	int ans = 0;
	loop(i, 1, s.size() - 1) {
		loop(start, 0, s.size() - 1) {
			bool yes = 1;
			loop(j, start, start + i - 1) {
				if (j + i >= s.size()) {
					yes = 0;
					break;
				}
				if (s[j] == s[j + i] || s[j + i] == '.') continue;
				yes = 0;
			}
			if (yes) {
				ans = i;
				break;
			}
		}
	}
	cout << 2 * ans;
}