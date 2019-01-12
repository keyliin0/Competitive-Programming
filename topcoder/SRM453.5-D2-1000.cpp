/*
	if the previous result of all multiplication is negative , then we need to minimize our next result 
	otherwise we need to maximize
	we can solve this with dp state : [current index] [last index used] [needed numbers] [positive or negative]
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll dp[55][100][55][2];
vector<ll> t;
int d;
ll inf = 1e18;

ll solve(int i,int last,int rem,int p) {
	if (rem == 0) return 1;
	if (i >= t.size() || (i - last > d && last != 55)) {
		if (rem) {
			if (p) return -inf;
			return inf;
		}
		return 1;
	}
	ll &ret = dp[i][last][rem][p];
	if(ret != -1) return ret;
	if(p) ret = -inf;
	else ret = inf;
	for (int j = 1; j <= d; j++) {
		ll x;
		if (p) {
			x = solve(i + j, i, rem - 1, t[i] >= 0 ? 1 : 0);
			if(x == inf || x == -inf) continue;
			ret = max(ret, t[i] * solve(i + j, i, rem - 1, t[i] >= 0 ? 1 : 0));
		} else {
			x = solve(i + j, i, rem - 1, t[i] >= 0 ? 1 : 0);
			if(x == inf || x == -inf) continue;
			ret = min(ret, t[i] * solve(i + j, i, rem - 1, t[i] >= 0 ? 0 : 1));
		}
	}
	ll x = solve(i + 1, last, rem, p);
	if(x != -inf && x != inf){
		if(p) ret = max(ret,x);
		else ret = min(ret,x);
	}
	return ret;
}

class TheProduct {
public:
	ll maxProduct(vector <int> numbers, int k, int maxDist) {
		for(int i = 0;i < numbers.size();i++)
			t.push_back(numbers[i]);
		d = maxDist;
		memset(dp,-1,sizeof dp);
		return solve(0, 55, k, 1);
	}
};
