/*
	go through all possible cases and memo
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
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, goal, p, start;
double dp[55][1009][55];
bool vis[55][1009][55];

class TestBettingStrategy {
public:
	double solve(int i, int curr, int lost) {
		if (curr >= goal) return 1.0;
		if (i == n || (1 << lost) > curr) return 0.0;
		if (vis[i][curr][lost]) return dp[i][curr][lost];
		vis[i][curr][lost] = 1;
		double &ret = dp[i][curr][lost];
		ret += (p / 100.0) * solve(i + 1, curr + (1 << lost), 0);
		ret += (1.0 - (p / 100.0)) * solve(i + 1, curr - (1 << lost), lost + 1);
		return ret;
	}
	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		start = initSum, goal = goalSum, n = rounds, p = prob;
		double ans = solve(0, start, 0);
		return ans;
	}
};
