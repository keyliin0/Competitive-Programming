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

int a, b;

bool can(int i) {
	int x = 0;
	while (i != 0) {
		if (i % 10 == 7 || i % 10 == 4) x = x * 10 + i % 10;
		i /= 10;
	}
	return x == b;
}

int main() {
	cin >> a >> b;
	if (b > a) {
		cout << b;
		return 0;
	}
	string comp = to_string(b);
	reverse(comp.begin(), comp.end());
	b = stoi(comp);
	loop(i, a + 1, 1e7) {
		if (can(i)) {
			cout << i;
			break;
		}
	}
}