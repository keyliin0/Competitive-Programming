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

int n, m;
int t[N];
bool f[N];
set<int> s[100005];
bool l[N];

bool valid(int x) { return x >= 1 && x <= n;  }

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, m - 1) {
		scanf("%d", &t[i]);
		f[t[i]] = 1;
	}
	ll ans = 0;
	loop2(i, m - 1, 0) {
		if (valid(t[i] - 1) && l[t[i] - 1]) s[t[i]].insert(t[i] - 1);
		if (valid(t[i] + 1) && l[t[i] + 1]) s[t[i]].insert(t[i] + 1);
		l[t[i]] = 1;
	}
	loop(i, 1, n) {
		if (!f[i]) {
			ans++;
			ans += valid(i - 1);
			ans += valid(i + 1);
		}
		else {
			ans += valid(i - 1) + valid(i + 1) - s[i].size();
		}
	}
	cout << ans;
}