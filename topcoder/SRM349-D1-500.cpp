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

ll dp[40][40];
vector<int> v;

class DiceGames {
public:
	ll calc(int i,int s) {
		if (i == v.size()) return 1;
		ll &ret = dp[i][s];
		if (ret != -1) return ret;
		ret = 0;
		for (int j = s; j <= v[i]; j++)
			ret += calc(i + 1, j);
		return ret;
	}
	ll countFormations(vector<int> sides) {
		memset(dp, -1, sizeof dp);
		v = sides;
		sort(v.begin(), v.end());
		return calc(0, 1);
	}

};