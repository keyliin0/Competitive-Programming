/*
	get prime factorazation for each n ∗ (n − k) ∗ (n − 2k) ....
	now that we have the power of each prime the number of divisors is 
	product of power of the current prime + 1
	example :
	lets say the the prime facotrs are 2^a + 3 ^b 
	then the number of divisors is (a + 1) * (b + 1)
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e5;
int oo = 1e5;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

char C[25];
int n;
vector<int> v[1005];
ll cnt[1005];

int main() {
	loop(i, 1, 1000) {
		int x = i;
		for (int j = 2; j * j <= x; j++) {
			while (x % j == 0) {
				v[i].push_back(j);
				x /= j;
			}
		}
		if (x != 1) v[i].push_back(x);
	}
	int test;
	scanf("%d",&test);
	int cas = 0;
	while (test--) {
		scanf("%d%s", &n, C);
		int k = strlen(C);
		memset(cnt, 0, sizeof cnt);
		for (int i = n; i > 0; i -= k) {
			for (auto d : v[i])
				cnt[d]++;
		}
		ll ans = 1;
		ll inf = 1e18;
		loop(i, 1, n) {
			ans *= cnt[i] + 1;
			if (ans > inf) break;
		}
		cas++;
		printf("Case %d: ",cas);
		if(ans > inf) printf("Infinity\n");
		else printf("%lld\n",ans);
	}
}
