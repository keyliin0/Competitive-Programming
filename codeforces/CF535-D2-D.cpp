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

string s;
int f[N],t[N];
int n, m;
char s2[N];
bool marked[N];

void search() {
	int idx = 0, len = 0;
	for (int i = 0; i < n; i++) {
		while (len > 0 && s2[i] != s[len])
			len = f[len - 1];
		if (s2[i] == s[len])
			len++;
		if (len == s.size()) {
			//cout << i - len + 1 << " ";
			marked[i - len + 1] = 0;
			len = f[len - 1];
		}
	}
}

void calc() {
	int len = 0;
	for (int i = 1; i < s.size(); i++) {
		while (len > 0 && s[i] != s[len])
			len = f[len - 1];
		if (s[i] == s[len])
			len++;
		f[i] = len;
	}
}

int main() {
	io;
	cin >> n >> m >> s;
	loop(i, 0, m - 1) {
		cin >> t[i];
		marked[t[i] - 1] = 1;
	}
	int idx = 1e7;
	loop(i, 0, n - 1) {
		if (marked[i]) idx = 0;
		if (idx < s.size()) {
			s2[i] = s[idx];
			idx++;
		}
		else s2[i] = '@';
	}
	calc();
	search();
	ll ans = 1;
	loop(i, 0, n - 1) {
		if (marked[i]) {
			cout << "0";
			return 0;
		}
		if (s2[i] == '@') ans = (ans * 26) % mod;
	}
	cout << ans;
}