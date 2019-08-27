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
 
string s;
int k;
int b = 1;
 
ll dp[1005][1005][2];
int v[1005];
 
ll solve(int i, int j, int f) {
	if (i == s.size()) {
		return v[j] == 1;
	}
	ll &ret = dp[i][j][f];
	if (ret != -1) return ret;
	ret = 0;
	if (f) {
		ret += solve(i + 1, j + 1, 1);
		ret %= mod;
		ret += solve(i + 1, j, 1);
		ret %= mod;
	}
	else {
		if(s[i] == '0')
			ret += solve(i + 1, j, 0);
		else ret += solve(i + 1, j, 1);
		ret %= mod;
		if(s[i] == '1') ret += solve(i + 1, j + 1, 0);
		ret %= mod;
	}
	return ret;
}
 
int main() {
	cin >> s >> k;
	if (k == 0) {
		cout << 1;
		return 0;
	}
	loop(i, 1, 1000) {
		int x = i, cnt = 0;
		while (x != 1) {
			int s = 0;
			for (int j = 0; j < 12; j++)
				if (x & (1 << j)) s++;
			x = s;
			cnt++;
		}
		if (cnt == k - 1) v[i] = 1;
	}
	memset(dp, -1, sizeof dp);
	cout << (((solve(0, 0, 0) - (k == 1)) % mod) + mod) % mod;
}