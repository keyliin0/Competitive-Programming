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

string s1, s2;
int f[N];
int n;

void calc() {
	int len = 0;
	for (int i = 1; i < s1.size(); i++) {
		while (len > 0 && s1[i] != s1[len])
			len = f[len - 1];
		if (s1[i] == s1[len])
			len++;
		f[i] = len;
		if ((i + 1 - f[i]) && (i + 1) % (i + 1 - f[i]) == 0 && (i + 1) / (i + 1 - f[i]) > 1) {
			cout << i + 1 << " " << (i + 1) / (i + 1 - f[i]) << "\n";
		}
	}
}

int main() {
	int test;
	cin >> test;
	loop(t,1,test) {
		cin >> n >> s1;
		cout << "Test case #" << t << "\n";
		calc();
		cout << "\n";
	}
}