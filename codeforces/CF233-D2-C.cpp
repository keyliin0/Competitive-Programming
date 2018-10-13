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

int k;
bool g[105][105];


int main() {
	scanf("%d", &k);
	int cnt = 2;
	g[0][1] = g[1][0] = g[0][2] = g[2][0] = g[1][2] = g[2][1] = 1;
	k--;
	for (int i = 3; k; i++) {
		cnt = i;
		for (int j = 0; j < i && k; j++) {
			if (k - j < 0) break;
			k -= j;
			g[i][j] = g[j][i] = 1;
		}
	}
	printf("%d\n", cnt + 1);
	loop(i, 0, cnt) {
		loop(j, 0, cnt) {
			printf("%d",g[i][j]);
		}
		puts("");
	}
}