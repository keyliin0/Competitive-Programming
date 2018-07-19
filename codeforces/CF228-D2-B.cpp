/*
	any value of x and y > 50 or < -50 is useless since n and m <= 50 
	so we can just do a brute force for x and y in [-50..50]
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

int n1,m1,n2,m2;
char g1[55][55], g2[55][55];

int main() {
	scanf("%d%d",&n1,&m1);
	loop(i, 0, n1 - 1)
		scanf("%s",g1[i]);
	scanf("%d%d",&n2,&m2);
	loop(i, 0, n2 - 1) 
		scanf("%s",g2[i]);
	int mx = -oo,ax,ay;
	loop(x, -50, 50) {
		loop(y, -50, 50) {
			int curr = 0;
			loop(i, 0, n1 -1) {
				loop(j, 0, m1 - 1) {
					if (i + x >= n2 || i + x < 0 || j + y >= m2 || j + y < 0) continue;
					curr += (g1[i][j] - '0') * (g2[i + x][j + y] - '0');
				}
			}
			if (curr > mx) mx = curr, ax = x, ay = y;
		}
	}
	printf("%d %d",ax,ay);
}