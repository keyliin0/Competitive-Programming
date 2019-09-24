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
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, k, q;
int f[N];

int main() {
	scanf("%d%d%d", &n, &k, &q);
	while (n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		f[l]++;
		f[r + 1]--;
	}
	loop(i, 1, 200000)
		f[i] += f[i - 1];
	loop(i, 1, 200000) {
		if (f[i] >= k) f[i] = 1;
		else f[i] = 0;
		f[i] += f[i - 1];
	}
	while (q--) {
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n",f[r] - f[l - 1]);
	}

}