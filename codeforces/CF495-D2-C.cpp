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

string s;

int main() {
	cin >> s;
	int idx;
	int total = 0, totalc = 0;
	int cnt = 0;
	loop(i, 0, s.size() - 1) {
		if (s[i] == '#') idx = i, cnt++;
		total += s[i] == '(';
		totalc += s[i] == ')';
	}
	int o = 0, c = 0;
	int ans;
	loop(i, 0, s.size() - 1) {
		if (s[i] == '(') o++;
		else if (s[i] == ')') c++,totalc--;
		else if (i != idx) c++;
		else {
			if (total - c - totalc < 1) {
				printf("-1");
				return 0;
			}
			ans = total - c - totalc;
			c += total - c - totalc;
		}
		if (c > o) {
			printf("-1");
			return 0;
		}
	}
	loop(i, 1, cnt - 1)
		printf("1\n");
	printf("%d",ans);
}