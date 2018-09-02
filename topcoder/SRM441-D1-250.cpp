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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

bool f[51];

class PerfectPermutation{
public:
	int reorder(vector<int> p) {
		int ans = 0;
		loop(i, 0, p.size() - 1) {
			if (!f[i]) {
				f[i] = 1;
				int x = i;
				while (!f[p[x]]) {
					f[p[x]] = 1;
					x = p[x];
				}
				ans++;
			}
		}
		if (ans == 1) return 0;
		else return ans;
	}
};