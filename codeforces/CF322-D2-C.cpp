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
 
int a, b;
string s;
 
int main() {
	cin >> a >> b >> s;
	int x = 0, y = 0;
	loop(i, 0, s.size() - 1) {
		if (x == a && y == b) {
			printf("Yes");
			return 0;
		}
		if (s[i] == 'U') y++;
		if (s[i] == 'D') y--;
		if (s[i] == 'L') x--;
		if (s[i] == 'R') x++;
	}
	if (x == a && y == b) {
		printf("Yes");
		return 0;
	}
	int cx = 0, cy = 0;
	loop(i, 0, s.size() - 1) {
		int aa = a - cx;
		int bb = b - cy;
		if (x) {
			int m = abs(aa / x);
			int xx = m * x + cx;
			int yy = m * y + cy;
			if (xx == a && yy == b) {
				printf("Yes");
				return 0;
			}
		}
		if (y) {
			int m = abs(bb / y);
			int xx = m * x + cx;
			int yy = m * y + cy;
			if (xx == a && yy == b) {
				printf("Yes");
				return 0;
			}
		}
		if (s[i] == 'U') cy++;
		if (s[i] == 'D') cy--;
		if (s[i] == 'L') cx--;
		if (s[i] == 'R') cx++;
	}
	int aa = a - cx;
	int bb = b - cy;
	if (x) {
		int m = abs(aa / x);
		int xx = m * x + cx;
		int yy = m * y + cy;
		if (xx == a && yy == b) {
			printf("Yes");
			return 0;
		}
	}
	if (y) {
		int m = abs(bb / y);
		int xx = m * x + cx;
		int yy = m * y + cy;
		if (xx == a && yy == b) {
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}