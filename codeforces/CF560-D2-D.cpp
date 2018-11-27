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


char a[N], b[N];

bool solve(int i,int j,int len) {
	bool yes = 1;
	for (int k = 0; k < len; k++) {
		if (a[i + k] != b[j + k]) {
			yes = 0;
			break;
		}
	}
	if (yes) return 1;
	if (len % 2 != 0) return 0;
	yes = solve(i, j, len / 2) && solve(i + len / 2, j + len / 2, len / 2);
	if (yes) return yes;
	yes = solve(i, j + len / 2, len / 2) && solve(i + len / 2, j, len / 2);
	return yes;
}

int main() {
	scanf("%s%s", a, b);
	if (solve(0, 0, strlen(a))) printf("YES");
	else printf("NO");
}