/*
	we can reach first & second segment only with one way
	the number of ways to reach the ith segment way[i] = way[i - 1] + way[i - 2] 
	it's fibonacci sequence
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
#define logg2  0.30102999566398119521373889472449L
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

int n, k;
int fib[605];
int dp[605][605][2], dp2[605][605][2];
int MOD = 555555555;

class MuddyRoad2 {
public:
	// function to find the number of roads such that we can reach segment N with even number of ways 
	int solve(int i, int rem, int m) {
		if (i == n) return rem == 0 && m == 0;
		if (rem == 0) return (fib[n - i + 1] * m) % 2 == 0;
		int &ret = dp[i][rem][m];
		if (ret != -1) return ret;
		ret = 0;
		for (int j = i + 1; j < n; j++) {
			ret = (ret + solve(j + 1, rem - 1, (m * fib[j - i]) % 2)) % MOD;
		}
		return ret;
	}
	// function to find the number of roads when we cant reach the segment N
	int solve2(int i, int rem, bool f) {
		if (rem < 0) return 0;
		if (i == n) return f && rem == 0;
		int &ret = dp2[i][rem][f];
		if (ret != -1) return ret;
		ret = 0;
		for (int j = i; j < n; j++) {
			ret = (ret + solve2(j + 1, rem - (j - i), f || ((j - i) >= 2))) % MOD;
		}
		return ret;
	}
	int theCount(int N, int muddyCount) {
		n = N;
		k = muddyCount;
		fib[1] = fib[2] = 1;
		for (int i = 3; i <= 600; i++)
			fib[i] = (fib[i - 1] + fib[i - 2]) % 2;
		memset(dp, -1, sizeof dp);
		memset(dp2, -1, sizeof dp2);
		int ans = solve(1, k, 1);
		int ans2 = solve2(1, k, 0);
		return (ans + ans2) % MOD;
	}
};