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

int n;
char m1[12][12];
char m3[12][12];
char m2[12][12];
char m4[12][12];
string deg[3] = { "90 degrees.","180 degrees.", "270 degrees." };

bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (m1[i][j] != m2[i][j]) return 0;
	return 1;
}

void rotate() { // rotate 90 deg
	char tmp[12][12];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			tmp[i][j] = m1[n - 1 - j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = tmp[i][j];
		}
	}
}

int main() {
	io;
	int test = 0;
	while (cin >> n) {
		test++;
		cout << "Pattern " << test << " ";
		loop(i, 0, n - 1) {
			loop(j, 0, n - 1) {
				cin >> m1[i][j];
				m4[i][j] = m1[i][j];
			}
			loop(j, 0, n - 1)
				cin >> m2[i][j];
		}
		if (check()) {
			cout << "was preserved." << endl;
			continue;
		}
		bool sol = 0;
		loop(i, 0, 2) {
			rotate();
			if (check()) {
				sol = 1;
				cout << "was rotated " << deg[i] << endl;
				break;
			}
		}
		if (sol) continue;
		loop(i, 0, n - 1)
			loop(j, 0, n - 1)
				m1[i][j] = m4[i][j];
		for (int i = 0; i < n / 2; i++) {
			swap(m1[i], m1[n - i - 1]);
		}
		if (check()) {
			cout << "was reflected vertically." << endl;
			continue;
		}
		loop(i, 0, 2) {
			rotate();
			if (check()) {
				sol = 1;
				cout << "was reflected vertically and rotated " << deg[i] << endl;
				break;
			}
		}
		if (!sol) cout << "was improperly transformed." << endl;
	}
}