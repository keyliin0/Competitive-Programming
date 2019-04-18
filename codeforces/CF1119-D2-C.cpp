#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int A[505][505], B[505][505];
int n, m;
int r[505], c[505];

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			scanf("%d", &A[i][j]);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			scanf("%d", &B[i][j]);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1) {
			r[i] += A[i][j] != B[i][j];
			c[j] += A[i][j] != B[i][j];
	}
	bool yes = 1;
	loop(i, 0, n - 1)
		if (r[i] % 2 != 0) yes = 0;
	loop(i, 0, m - 1)
		if (c[i] % 2 != 0) yes = 0;
	cout << (yes ? "Yes" : "No");
}