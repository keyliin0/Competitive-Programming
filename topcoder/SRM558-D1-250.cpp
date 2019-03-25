/*
	try every stamp length 
	for each length find the min number of pushes needed with dp
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int len;
string s;
char C[] = { 'R','G','B' };
int dp[55][55][5];

class Stamp {
public:
	int solve(int i,int rem,int c) {
		if (i == s.size()) return 0;
		if (i + len - 1 == s.size()) return rem == s.size() - i ? 0 : oo;
		int &ret = dp[i][rem][c];
		if (ret != -1) return ret;
		ret = oo;
		if (rem != 0) {
			bool can = 1;
			loop(j, i, i + len - 1) {
				loop(k, 0, 2) {
					if (C[k] == s[j] && c != k)
						can = 0;
				}
			}
			if (can) ret = min(ret, 1 + solve(i + 1, len - 1, c));
			ret = min(ret, solve(i + 1, rem - 1, c));
		}
		else {
			bool can = 1;
			int current = -1;
			loop(j, i, i + len - 1) {
				loop(k, 0, 2) {
					if (C[k] == s[j] && current == -1) current = k;
					if (C[k] == s[j] && current != k)
						can = 0;
				}
			}
			if (can) {
				if (current == -1)
					loop(k, 0, 2) ret = min(ret, 1 + solve(i + 1, len - 1, k));
				else  ret = min(ret, 1 + solve(i + 1, len - 1, current));
			}
		}
		return ret;
	}
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		s = desiredColor;
		int ans = oo;
		loop(i, 1, s.size()) {
			len = i;
			memset(dp, -1, sizeof dp);
			int p = solve(0,0,0);
			if (p == oo) continue;
			ans = min(ans, len * stampCost + p * pushCost);
		}
		return ans;
	}
};

int main() {
	Stamp c;
	int ans = c.getMinimumCost("R*RR*GG", 10, 58);
	cout << ans;
}
