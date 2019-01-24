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

int n, m;
char g[105][105];
ll freq[105][26];

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		scanf("%s",g[i]);
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			freq[j][g[i][j] - 'A']++;
		}
	}
	ll ans = 1;
	loop(i, 0, m - 1) {
		ll curr = 0;
		loop(j, 0, 25) {
			if (freq[i][j]) curr++;
		}
		ans = (ans * curr) % mod;
	}
	printf("%lld",ans);
}