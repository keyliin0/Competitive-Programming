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

char ans[2 * N];
int n, m;

int main() {
	io;
	cin >> n >> m;
	int sz = n + m;
	int idx = 0;
	if (n > m) ans[idx] = '0', idx++, n--;
	while (m > n) {
		ans[idx] = '1';
		m--;
		idx++;
		if (m > n) ans[idx] = '1', idx++, m--;
		if (n) {
			ans[idx] = '0';
			idx++;
			n--;
		}
	}
	char c[] = { '1','0' };
	int cnt = 0;
	for (int i = idx; i < sz; i++, cnt++) {
		if (c[cnt % 2] == '1') {
			if (m == 0) {
				cout << -1;
				return 0;
			}
			m--;
			ans[i] = '1';
		}
		else {
			if (n == 0) {
				cout << -1;
				return 0;
			}
			n--;
			ans[i] = '0';
		}
	}
	int cntz = 0, cnto = 0;
	for (int i = 0; i < sz; i++) {
		if (ans[i] == '1') {
			cntz = 0;
			if (cnto == 2) {
				cout << -1;
				return 0;
			}
			cnto++;
		}
		else {
			cnto = 0;
			if (cntz) {
				cout << -1;
				return 0;
			}
			cntz++;
		}
	}
	for (int i = 0; i < sz; i++)
		cout << ans[i];
}