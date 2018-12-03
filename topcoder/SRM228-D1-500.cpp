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

vector<int> t;
int dp[52][52][2];

class BagsOfGold {
public:
	int solve(int l, int r, bool f) {
		if (l == r) {
			if (f) return t[r];
			else return -t[r];
		}
		int &ret = dp[l][r][f];
		if (ret != oo) return ret;
		if (f) { // f = 1 is the one who wants to maximize the difference 
			ret = t[l] + solve(l + 1, r, !f);
			ret = max(ret, t[r] + solve(l, r - 1, !f));
		}
		else {
			ret = -t[l] + solve(l + 1, r, !f);
			ret = min(ret, -t[r] + solve(l, r - 1, !f));
		}
		return ret;
	}
	int netGain(vector <int> bags) {
		t = bags;
		for (int i = 0; i < t.size(); i++)
			for (int j = 0; j < t.size(); j++)
				for (int k = 0; k < 2; k++)
					dp[i][j][k] = oo;
		int ans = solve(0, t.size() - 1, 1);
		return ans;
	}
};
