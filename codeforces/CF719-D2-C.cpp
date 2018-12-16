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

int n, t;
string s;

int main() {
	io;
	cin >> n >> t >> s;
	int v_idx = -1, idx = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') v_idx = i;
		else if (idx == -1 && v_idx != -1 && (s[i] - '0') >= 5) idx = i;
	}
	if (idx == -1) {
		cout << s;
		return 0;
	}
	for (int i = idx + 1; i < s.size(); i++)
		s[i] = '0';
	for (int i = idx; i > v_idx && t; i--) {
		if ((s[i] - '0') >= 5) {
			t--;
			s[i] = '0';
			while (i > 0 && (s[i - 1] == '9' || s[i - 1] == '.')) {
				if (s[i - 1] == '.') {
					i--;
					continue;
				}
				s[i - 1] = '0';
				i--;
			}
			if (i > 0) s[i - 1]++;
		}
	}
	int end = v_idx - 1;
	int f = 0;
	if (s[0] == '0') s = '1' + s, end++, f = 1;
	for (int i = v_idx + f + 1; i < s.size(); i++)
		if (s[i] != '0') end = i;
	for (int i = 0; i <= end; i++)
		cout << s[i];
}