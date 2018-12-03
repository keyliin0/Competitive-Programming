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

string s;
int dp[1 << 14][2];

class RowAndCoins {
public:
	int cnt(int mask) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
			if (!(mask &(1 << i))) cnt++;
		return cnt;
	}

	int solve(int mask, bool alice) {
		if (dp[mask][alice] != -1) return dp[mask][alice];
		int empty = cnt(mask);
		if (empty == 1) {
			bool alice_win;
			for (int i = 0; i < s.size(); i++) {
				if (!(mask &(1 << i)))
					alice_win = s[i] == 'A';
			}
			if (!alice) return alice_win;
			else return !alice_win;
		}
		for (int i = 0; i < s.size(); i++) {
			int curr_mask = mask;
			for (int j = i; j < s.size(); j++) {
				if (mask & (1 << j) || j - i + 1 >= empty) break;
				curr_mask |= (1 << j);
				int res = solve(curr_mask, !alice);
				if (res) return dp[mask][alice] = 0;
			}
		}
		return dp[mask][alice] = 1;
	}
	string getWinner(string cells) {
		s = cells;
		memset(dp, -1, sizeof dp);
		return solve(0, 1) ? "Bob" : "Alice";
	}
};
