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

int a, b, c, m, n;
int t[N], freq[N];

int main() {
	int test;
	scanf("%d", &test);
	loop(tt, 1, test) {
		scanf("%d%d%d%d%d", &a, &b, &c, &m, &n);
		memset(freq, 0, sizeof freq);
		t[0] = a;
		loop(i, 1, n - 1) {
			t[i] = ((t[i - 1] * b + c) % m) + 1;
		}
		loop(i, 1, n - 1) {
			t[i] += t[i - 1];
			freq[t[i] % m]++;
		}
		freq[t[0] % m]++;
		int ans = freq[0];
		freq[t[0] % m]--;
		loop(i, 1, n - 1) {
			ans += freq[t[i - 1] % m];
			freq[t[i] % m]--;
		}
		printf("Case %d: %d\n", tt, ans);
	}
}