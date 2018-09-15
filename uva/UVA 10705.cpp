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
string s;
ll m;

int main() {
	io;
	int test;
	cin >> test;
	while (test--) {
		cin >> n >> s >> m;
		string ans = "";
		loop2(i, n - 1, 0) {
			if (m & 1) {
				ans = '1' + ans;
				int tmp = 0;
				if (s[i] == 'n' && m > 0) {
					tmp = 1;
				}
				if (s[i] == 'p' && m < 0) {
					tmp = -1;
				}
				m /= 2;
				m += tmp;
			}
			else {
				ans = '0' + ans;
				m /= 2;
			}
		}
		if(m == 0) cout << ans << endl;
		else cout << "Impossible" << endl;
	}
}