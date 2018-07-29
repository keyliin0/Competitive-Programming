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
string types[] = { "lios","etr","initis","liala","etra","inites" };

int type(string s) {
	string tmp = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		tmp = s[i] + tmp;
		for (int j = 0; j < 6; j++)
			if (types[j] == tmp) return j + 1;
		if (s.size() - i > 6) return -1;
	}
	return -1;
}

int main() {
	io;
	bool yes = 1;
	int gender = -1;
	int adj = 0, noun = 0, ver = 0;
	int cnt = 0;
	while(cin >> s) {
		int t = type(s);
		if (t == -1) {
			cout << "NO";
			return 0;
		}
		if (gender == -1) {
			if (t > 3) gender = 1;
			else gender = 0;
		}
		if (t > 3 && gender == 0) yes = 0;
		if (t <= 3 && gender == 1) yes = 0;
		t = (t - 1) % 3;
		if (t == 1) {
			if (ver != 0 || noun != 0) yes = 0;
			noun++;
		}
		else if (t == 0) {
			if (noun != 0 || ver != 0) yes = 0;
			adj++;
		}
		else {
			if (adj != 0 && noun != 1) yes = 0;
			ver++;
		}
		cnt++;
	}
	if (cnt > 1 && noun != 1) yes = 0;
	cout << (yes ? "YES" : "NO");
}