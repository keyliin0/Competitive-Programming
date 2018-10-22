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

ll a, b;
vector<int> ans[2];

int main() {
	scanf("%lld%lld",&a,&b);
	ll l = 0, r = (a + b), x;
	while (l <= r) {
		ll m = (l + r) / 2;
		if ((m * (m + 1)) / 2 <= a + b) {
			x = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	for (ll i = x; i >= 1; i--) {
		if (a >= i) {
			a -= i;
			ans[0].push_back(i);
		}
		else if (b >= i) {
			b -= i;
			ans[1].push_back(i);
		}
	}
	printf("%d\n", ans[0].size());
	for (int i = 0; i < ans[0].size(); i++) {
		printf("%d ", ans[0][i]);
	}
	printf("\n");
	printf("%d\n", ans[1].size());
	for (int i = 0; i < ans[1].size(); i++) {
		printf("%d ", ans[1][i]);
	}
}