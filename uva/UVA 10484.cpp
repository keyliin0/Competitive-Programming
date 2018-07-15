/*
	explanation at https://www.quora.com/What-is-the-idea-behind-solving-Divisibility-of-factors-UVa-10484
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

int n;
ll d;
int freq[105];

int main() {
	while (scanf("%d%lld", &n, &d)) {
		d = abs(d);
		memset(freq, 0, sizeof freq);
		if (n == 0 && d == 0) return 0;
		for (int i = 2; i <= n; i++) {
			int tmp = i;
			for (int j = 2; j <= tmp; j++)
				while (tmp % j == 0) freq[j]++, tmp /= j;
		}
		bool zero = 0;
		for (int i = 2; i <= 100 && !zero; i++) {
			while (d % i == 0) {
				if (freq[i] <= 0) {
					zero = 1;
					break;
				}
				freq[i]--;
				d /= i;
			}
		}
		if (zero || d > 100 || (d > 1 && freq[d] <= 0)) {
			printf("0\n");
			continue;
		}
		else if (d > 1) freq[d]--;
		ll ans = 1;
		loop(i, 2, 100)
			ans *= (ll)freq[i] + 1;
		printf("%lld\n", ans);
	}
}
