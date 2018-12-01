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
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
int dp[1 << 20];

class EllysCheckers {
public:
	int solve(int mask) {
		if (mask == 0) return 1; //if i lose the previous player win
		if (dp[mask] != -1) return dp[mask];
		for (int i = 0; i < n - 1; i++) {
			if (mask & (1 << i)) {
				if (mask & (1 << (i + 1)) && mask & (1 << (i + 2)) && !(mask & (1 << (i + 3))) && i + 3 < n) {
					int new_mask = mask ^ (1 << i);
					if (i + 3 < n - 1) new_mask |= (1 << (i + 3));
					int res = solve(new_mask);
					if (res) return dp[mask] = 0; // if i win the previous player lose
				}
				if (!(mask & (1 << (i + 1)))) {
					int new_mask = mask ^ (1 << i);
					if (i + 1 < n - 1) new_mask |= (1 << (i + 1));
					int res = solve(new_mask);
					if (res) return dp[mask] = 0; // if i win the previous player lose
				}
			}
		}
		return dp[mask] = 1; // if i lose the previous player win
	}
	string getWinner(string board) {
		int mask = 0;
		for (int i = 0; i < board.size() - 1; i++)
			if (board[i] == 'o') mask |= (1 << i);
		n = board.size();
		memset(dp, -1, sizeof dp);
		int res = solve(mask);
		return res ? "NO" : "YES";
	}
};