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

ll l, r;

int main() {
	scanf("%lld%lld", &l, &r);
	ll ans = 0;
	bool yes = 0;
	int idx = -1;
	for (int i = 63; i >= 0; i--) {
		if ((l & (1LL << i)) != (r & (1LL << i))) {
			idx = i;
			break;
		}
	}
	for (int i = idx; i >= 0; i--) {
		ans += (1LL << i);
	}
	printf("%lld",ans);
}