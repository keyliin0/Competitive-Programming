/*
	normal dp wont fit in memory
	if we try a bottom up approach we notice that we only need n - 1 (or k - 1 depending on the implementation) to calculate the current n
	so only store the last n
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
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 9;
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int prime[1005];
ll dp[2][200][201];
ll fact[1005][201];

class MegaFactorialDiv2 {
public:
	void decomp(int n) {
	int x = n;
	for (int i = 2; i <= n / i; i++) {
		while (n % i == 0) {
			n /= i;
			fact[x][prime[i]]++;
		}
	}
	if (n > 1) fact[x][prime[n]]++;
	}

	int countDivisors(int n,int k){
		int cnt = 0;
	loop(i, 2, n) {
		bool isprime = 1;
		loop(j, 2, i - 1) {
			if (i % j == 0) isprime = 0;
		}
		if (isprime) {
			cnt++;
			prime[i] = cnt;
		}
	}
	loop(i, 2, n) {
		decomp(i);
	}
	loop(i, 1, n) {
		memset(dp[i % 2], 0, sizeof(dp[i % 2]));
		loop(j, 0, k) {
			loop(p, 0, 200) {
				if (j == 0) dp[i % 2][j][p] = fact[i][p] % mod;
				else {
					dp[i % 2][j][p] += dp[i % 2][j - 1][p] % mod;
					dp[i % 2][j][p] %= mod;
					dp[i % 2][j][p] += (dp[(i - 1) % 2][j][p]) % mod;
					dp[i % 2][j][p] %= mod;
				}
			}
		}
	}
	ll ans = 1;
	loop(p, 1, 200) {
		ans = (ans * (dp[n % 2][k][p] + 1)) % mod;
	}
	return ans;
	}
	
};