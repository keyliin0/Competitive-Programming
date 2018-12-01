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

bool prime[1005];

void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
}

int main() {
	generateprime(200);
	int cnt = 0;
	int div = -1;
	for (int i = 2; i <= 47; i++) {
		if (prime[i]) {
			cout << i << "\n";
			fflush(stdout);
			string s;
			cin >> s;
			if (s == "yes") {
				cnt++;
				div = i;
			}
		}
	}
	if (cnt == 0) {
		cout << "prime";
		fflush(stdout);
		return 0;
	}
	if (cnt > 1) {
		cout << "composite";
		fflush(stdout);
		return 0;
	}
	for (int i = div * div; i <= 100; i *= div) {
		cout << i << "\n";
		fflush(stdout);
		string s;
		cin >> s;
		cnt += s == "yes";
	}
	if(cnt > 1) cout << "composite";
	else cout << "prime";
	fflush(stdout);
	return 0;
}