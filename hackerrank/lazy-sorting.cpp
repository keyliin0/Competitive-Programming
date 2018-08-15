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

int n;
int freq[101], t[20];

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		freq[t[i]]++;
	}
	bool is_sorted = 1;
	loop(i, 0, n - 2) {
		is_sorted &= t[i] <= t[i + 1];
	}
	if (is_sorted) {
		printf("0.0000");
		return 0;
	}
	ll d = 1;
	loop(i, 1, 100) {
		loop(j, 1, freq[i])
			d = (ll)d * j;
	}
	ll fact = 1;
	loop(i, 2, n)
		fact = (ll)fact *  i;
	printf("%lld.0000", fact / d);
}