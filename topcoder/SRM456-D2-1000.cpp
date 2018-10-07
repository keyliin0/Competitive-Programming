/*
	use binary search to check for the max value
	for precision run it several times
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

class CutSticks {
public:
	double maxKth(vector <int> sticks, int c, int k) {
		double l = 0, r = 0, ret;
		for (int i = 0; i < sticks.size(); i++) {
			r = max(r, (double)sticks[i]);
		}
		loop(j, 1, 1000000) {
			double m = (l + r) / 2.0;
			ll cnt = 0, exist = 0;
			for (int i = 0; i < sticks.size(); i++) {
				if ((double)sticks[i] / m - 1.0 >= EPS) exist++;
				double f = sticks[i];
				cnt += (ll)(f / m);
			}
			if (cnt >= k && c + exist >= k) ret = m, l = m + 1;
			else r = m - 1;
		}
		return ret;
	}
};
