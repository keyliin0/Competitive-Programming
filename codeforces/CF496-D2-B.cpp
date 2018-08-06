/*
	add to each digit +1 9 times and check the smallest number for every n shifting
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
int n;

int main() {
	io;
	cin >> n >> s;
	string ans = s;
	loop(j, 0, n - 1) {
		if (ans > s) ans = s;
		char tmp = s[n - 1];
		s.pop_back();
		s = tmp + s;
	}
	loop(i, 1, 9) {
		loop(j, 0, n - 1) {
			if (s[j] == '9') s[j] = '0';
			else s[j]++;
		}
		loop(j, 0, n - 1) {
			if (ans > s) ans = s;
			char tmp = s[n - 1];
			s.pop_back();
			s = tmp + s;
		}
		if (ans > s) ans = s;
	}
	cout << ans;
}