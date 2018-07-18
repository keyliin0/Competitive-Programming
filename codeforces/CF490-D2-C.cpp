/*
	count where a prefix of s % a = 0 and check if the rest % b = 0
	we can precalculate suffix of s % b by : mod[p]=  mod[p + 1] + (s[p] * (10^(s.size() - p - 1) % b))	
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

ll a, b;
string s;
ll mm[N];
ll p[N];

int main() {
	io;
	cin >> s >> a >> b;
	ll curr = 0;
	ll m = s[s.size() - 1] - '0';
	p[0] = 1;
	loop(i, 1, 1e6) {
		p[i] = (p[i - 1] * 10) % b;
	}
	for (int i = s.size() - 2; i >= 0; i--) {
		m += (s[i] - '0') * p[s.size() - i - 1];
		m %= b;
		mm[i] = m;
	}
	for (int i = 0; i < s.size() - 1; i++) {
		curr = (curr * 10 + s[i] - '0') % a;
		curr %= a;
		if (curr == 0 && mm[i + 1] == 0 && s[i + 1] != '0') {
			cout << "YES" << endl;
			for (int x = 0; x <= i; x++)
				cout << s[x];
			cout << endl;
			for (int x = i + 1; x < s.size(); x++)
				cout << s[x];
			return 0;
		}
	}
	cout << "NO";
}