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
int o[N], c[N], e;

int main() {
	io;
	cin >> n;
	int ans = 0;
	loop(i, 0, n - 1) {
		string s;
		cin >> s;
		int open = 0, close = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') open++;
			else {
				if (open == 0) close++;
				else open--;
			}
		}
		if (open == close && open == 0 && e) {
			e--;
			ans++;
		}
		else if (close == 0 && c[open]) {
			c[open]--;
			ans++;
		}
		else if (open == 0 && o[close]) {
			o[close]--;
			ans++;
		}
		else if (open == 0 && close == 0) e++;
		else if(open == 0 || close == 0){
			if (open) o[open]++;
			if (close) c[close]++;
		}
	}
	cout << ans;
}