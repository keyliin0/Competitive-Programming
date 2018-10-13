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

string s;
int dp[N];

bool is_set(int mask,int bit) {
	return mask & (1 << bit) ? 1 : 0;
}

int solve(int mask) {
	int &ret = dp[mask];
	//if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if(is_set(mask,i)) ret++;
	}
	for (int i = 0; i < s.size() - 2; i++) {
		if (!is_set(mask, i) && is_set(mask, i + 1) && is_set(mask, i + 2)) {
			int new_mask = mask;
			new_mask ^= 1 << (i + 2);
			new_mask ^= 1 << (i + 1);
			new_mask |= 1 << i;
			ret = min(ret, solve(new_mask));
		}
		if (is_set(mask, i) && is_set(mask, i + 1) && !is_set(mask, i + 2)) {
			int new_mask = mask;
			new_mask ^= 1 << i;
			new_mask ^= 1 << (i + 1);
			new_mask |= 1 << (i + 2);
			ret = min(ret, solve(new_mask));
		}
	}
	return ret;
}

int main() {
	io;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		int mask = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'o') mask |= 1 << i;
		}
		memset(dp, -1, sizeof dp);
		int ans = solve(mask);
		cout << ans << endl;
	}
}