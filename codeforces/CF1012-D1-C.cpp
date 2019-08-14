/*
	it we're at index i we can now if the i - 1 value was changed if we need it
	and we we can get its value :
	its either the same if t[i - 2] > t[i  - 1] or its t[i - 2] - 1  
*/
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
 
int dp[5001][2505][2];
int n;
int t[5001];
 
int solve(int i,int k,int f) {
	if (i >= n) {
		return k == 0 ? 0 : oo;
	}
	int &ret = dp[i][k][f];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, solve(i + 1, k, 0));
	if (!f) {
		int x = 0;
		if (i) x += max(0, t[i - 1] - t[i] + 1);
		if (i + 1 < n) x += max(0, t[i + 1] - t[i] + 1);
		ret = min(ret, x + solve(i + 2, k - 1, 1));
	}
	else {
		int x = 0;
		int y;
		if (t[i - 2] > t[i - 1]) y = t[i - 1];
		else y = t[i - 2] - 1;
		x += max(0, y - t[i] + 1);
		if (i + 1 < n) x += max(0, t[i + 1] - t[i] + 1);
		ret = min(ret, x + solve(i + 2, k - 1, 1));
	}
	return ret;
}
 
int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	memset(dp, -1, sizeof dp);
	loop(i, 1, (n + 1) / 2) {
		printf("%d ", solve(0, i, 0));
	}
}