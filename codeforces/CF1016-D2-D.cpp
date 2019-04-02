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
#define dp(a,b)                 ( (conj(a)*(b)).real() )
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

int n, m;
int ans[105][105];
int a[105], b[105];

int main() {
	scanf("%d%d",&n,&m);
	int xa = 0, xb = 0;
	loop(i, 0, n - 1) {
		scanf("%d", &a[i]);
		xa ^= a[i];
	}
	loop(i, 0, m - 1) {
		scanf("%d", &b[i]);
		xb ^= b[i];
	}
	if (xa != xb) {
		printf("NO");
		return 0;
	}
	loop(i, 0, m - 1)
		ans[n - 1][i] = b[i];
	loop(i, 0, n - 1)
		ans[i][m - 1] = a[i];
	int x = xa ^ a[n - 1] ^ b[m - 1];
	ans[n - 1][m - 1] = x;
	printf("YES\n");
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1)
			printf("%d ",ans[i][j]);
		puts("");
	}
}
