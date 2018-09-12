/*
	suppose the sum is S then count how many sub arrays have a sum <= S
	if the sum < k increase S otherwise make it lower and use binary search
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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, k;
ll t[N];

int check(ll m) {
	int x = 0;
	loop(i, 1, n) {
		int l = i, r = n , res = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (t[mid] - t[i - 1]  <= m) {
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(res != - 1) x += res - i + 1;
	}
	return x;
}

int main() {
	scanf("%d%d", &n, &k);
	loop(i, 1, n) {
		scanf("%lld", &t[i]);
		t[i] += t[i - 1];
	}
	if (n == 0) {
		printf("0");
		return 0;
	}
	ll l = 0, r = t[n], ans;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (check(m) >= k) {
			r = m - 1;
			ans = m;
		}
		else {
			l = m + 1;
			//ans = m;
		}
	}
	printf("%lld", ans);
}