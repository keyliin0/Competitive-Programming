/*
	 walk the island around with a "snake"
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

int a, b, c, d, n, t[26];
char g[500][500];


int main() {
	printf("YES\n");
	scanf("%d%d%d%d%d",&b,&a,&d,&c,&n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	int idx = 0;
	loop(i, 0, 200)
		loop(j, 0, 200)
			g[i][j] = '.';
	loop2(i, c, 1) {
		if (i % 2) {
			loop2(j, d + b, b + 1) {
				g[i][j] = 'a' + idx;
				t[idx]--;
				if (t[idx] == 0) idx++;
			}
		}
		else {
			loop(j, b + 1, d + b) {
				g[i][j] = 'a' + idx;
				t[idx]--;
				if (t[idx] == 0) idx++;
			}
		}
	}
	loop(i, 1, a) {
		if (i % 2) {
			loop2(j, b, 1) {
				g[i][j] = 'a' + idx;
				t[idx]--;
				if (t[idx] == 0) idx++;
			}
		}
		else {
			loop(j, 1, b) {
				g[i][j] = 'a' + idx;
				t[idx]--;
				if (t[idx] == 0) idx++;
			}
		}
	}
	loop(i, 1, max(a,c)) {
		loop(j, 1, b + d)
			cout << g[i][j];
		cout << endl;
	}
}
