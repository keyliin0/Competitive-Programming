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

int n;
int t[N];
int f[N];
int dp[4005][4005];

int main() {
	scanf("%d", &n);
	vector<int> v;
	loop(i, 1, n) {
		scanf("%d", &t[i]);
		v.push_back(t[i]);
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	f[v[0]] = cnt++;
	loop(i, 1, n - 1) {
		if (v[i] != v[i - 1])
			f[v[i]] = cnt++;
	}
	loop(i, 1, n)
		t[i] = f[t[i]];
	int ans = 1;
	loop(i, 1, n)
		loop(j, 1, cnt)
			dp[i][j] = 1;
	loop(i, 1, n) {
		loop(j, 1, i - 1) {
			dp[i][t[j]] = max(dp[i][t[j]], 1 + dp[j][t[i]]);
			ans = max(ans, dp[i][t[j]]);
		}
	}
	cout << ans;
}