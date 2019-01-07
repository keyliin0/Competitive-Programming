/*
	https://apps.topcoder.com/wiki/display/tc/SRM+537
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

vector<int> v;
bool vis[55];
double curr;

void dfs(int u,int cnt) {
	if (u != -1 && vis[u]) {
		curr = 0;
		return;
	}
	vis[u] = 1;
	curr = (double) curr / cnt;
	if (u != -1) dfs(v[u], cnt + 1);
}

class PrinceXToastbook {
public:
	double eat(vector <int> in) {
		v = in;
		double ans = 0;
		for (int i = 0; i < v.size(); i++) {
			memset(vis, 0, sizeof vis);
			curr = 1;
			vis[i] = 1;
			if(v[i] != -1) dfs(v[i], 1);
			ans += curr;
		}
		return ans;
	}
};
