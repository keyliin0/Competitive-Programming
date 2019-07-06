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
 
int n, m;
int t[N];
bool prime[N];
int pre[N];
map<int, int> p;
int dp[5005][5005];
vector<int> v;
int f[5005];
 
int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}
 
 
void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
	for (i = 2; i <= n; i++)
		if (prime[i]) v.push_back(i);
}
 
int calc2(int x) {
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		while (x % v[i] == 0) {
			if (p[v[i]]) res--;
			else res++;
			x /= v[i];
		}
	}
	if (x != 1) {
		if (p[x]) res--;
		else res++;
	}
	return res;
}
 
int calc(int i, int last) {
	if (i == -1) return 0;
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = -oo;
	ret = max(calc(i - 1, last) , calc(i - 1, i) - f[i] * (i + 1) + f[last] * (i + 1));
	return ret;
}
 
int main() {
	generateprime(31623);
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	loop(i, 0, m - 1) {
		int a;
		scanf("%d",&a);
		p[a] = 1;
	}
	pre[0] = t[0];
	loop(i, 1, n - 1) {
		pre[i] = GCD(pre[i - 1], t[i]);
	}
	int ans = 0;
	loop(i, 0, n - 1) {
		f[i] = calc2(pre[i]);
		ans += calc2(t[i]);
	}
	memset(dp, -1, sizeof dp);
	ans += calc(n - 1, n);
	printf("%d",ans);
}