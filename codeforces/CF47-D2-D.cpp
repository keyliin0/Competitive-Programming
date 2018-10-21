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

int n, m;
string s[50];
int t[50];
int ans;

void solve(int i) {
	if (i == n) {
		for (int k = 0; k < m; k++)
			if (t[k] != 0) return;
		ans++;
		return;
	}
	for (int j = 0; j < 2; j++) {
		bool go = 1;
		for (int k = 0; k < m; k++) {
			if (s[k][i] - '0' == j) {
				if (t[k] == 0) go = 0;
				t[k]--;
			}
		}
		if (go) solve(i + 1);
		for (int k = 0; k < m; k++)
			if (s[k][i] - '0' == j) t[k]++;
	}
}

int main() {
	cin >> n >> m;
	loop(i, 0, m - 1) {
		cin >> s[i] >> t[i];
	}
	solve(0);
	cout << ans;
}