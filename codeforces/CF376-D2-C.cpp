/*
	with 1 , 6 , 8 , 9 we can make any number mod 7 in [0 .. 6]
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
bool vis[10];
char c[] = { '1','6','8','9' };

int main() {
	cin >> s;
	int mod = 0, z = 0;
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			z++;
			continue;
		}
		bool y = 0;
		loop(j, 0, 3)
			if (s[i] == c[j])  y = 1;
		if (y && !vis[s[i] - '0']) {
			vis[s[i] - '0'] = 1;
			continue;
		}
		else {
			ans += s[i];
			mod = mod * 10 + (s[i] - '0');
			mod %= 7;
		}
	}
	string t = "1689";
	int curr = mod;
	for (int i = 0; i < t.size(); i++) {
		curr = (curr * 10) + (t[i] - '0');
		curr %= 7;
	}
	while (curr != 0) {
		next_permutation(t.begin(), t.end());
		curr = mod;
		for (int i = 0; i < t.size(); i++) {
			curr = (curr * 10) + (t[i] - '0');
			curr %= 7;
		}
	}
	cout << ans << t;
	loop(i, 1, z)
		cout << "0";
}