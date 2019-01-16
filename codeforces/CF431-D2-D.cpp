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

ll m;
int k;
ull C[100][100];

ull cnt(ull x) {
	int o = 0;
	ull res = 0;
	for (int i = 63; i >= 1; i--) {
		if (x & (1ULL << i)) {
			if(o <= k) res += C[i][k - o];
			o++;
		}
	}
	if (x & 1ULL) o++;
	return res + (o == k);
}

int main() {
	scanf("%lld%d", &m, &k);
	for (int i = 0; i <= 64; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i)
				C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	ull l = 1, r = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ull cnt1 = cnt(mid * 2);
		ull cnt2 = cnt(mid);
		if (cnt1 - cnt2 < m) {
			l = mid + 1;
		}
		else if (cnt1 - cnt2 > m) {
			r = mid - 1;
		}
		else {
			cout << mid;
			return 0;
		}
	}
}