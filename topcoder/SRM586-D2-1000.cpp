#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
ll dp[1005][30];

class StringWeightDiv2 {
public:
	ll calc(int l, int a) {
		if (l == 0) return a == 0;
		if (a == 0) return 0;
		ll &ret = dp[l][a];
		if (ret != -1) return ret;
		ret = 0;
		loop(i, 0, l - 1) 
			ret = (ret + calc(i, a - 1)) % mod;
		return ret;
	}
	ll factorial(int x){
		ll ret = 1;
		loop(i,0,x - 1)
			ret = (ret * (26 - i)) % mod;
		return ret;
	}
	int countMinimums(int l) {
		if (l <= 26) return (int)factorial(l);
		memset(dp, -1, sizeof dp);
		ll ans = (factorial(26) * calc(l, 26)) % mod;
		return ans;
	}

};
