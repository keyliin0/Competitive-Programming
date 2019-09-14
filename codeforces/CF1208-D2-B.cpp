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

map<int, int> mp;
bool vis[2005];
int t[N];
int n;

bool check(int l,int r) {
	memset(vis, 0, sizeof vis);
	loop(i, 0, l - 1) {
		if (vis[t[i]]) return 0;
		vis[t[i]] = 1;
	}
	loop(i, r + 1, n - 1) {
		if (vis[t[i]]) return 0;
		vis[t[i]] = 1;
	}
	return 1;
}

int main() {
	scanf("%d",&n);
	int cnt = 1;
	bool f = 1;
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		if (!mp[t[i]]) {
			mp[t[i]] = cnt++;
		}
		t[i] = mp[t[i]];
		if (vis[t[i]]) f = 0;
		vis[t[i]] = 1;
	}
	if (f) {
		printf("0");
		return 0;
	}
	int ans = oo;
	loop(i, 0, n - 1) {
		int l = 1, r = n - i;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(i,i + m - 1)) {
				ans = min(ans, m);
				r = m - 1;
			}
			else l = m + 1;
		}
	}
	printf("%d",ans);
}