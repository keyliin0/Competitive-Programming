/*
	fix the b and get the ans from b * k
	ans for b * k must be calculated first
	starting from the end of the array ans[b * k] += current frequency of b * k * k
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

ll t[N];
int n;
ll k;
ll m[N];
map<ll, ll> curr,freq;

int main() {
	scanf("%d%lld", &n,&k);
	loop(i, 0, n - 1) {
		scanf("%lld",&t[i]);
	}
	loop2(i, n - 1, 0) {
		curr[t[i]] += freq[t[i] *k];
		m[i] = freq[t[i] * k];
		freq[t[i]]++;
	}
	ll ans = 0;
	loop(i, 0, n - 1) {
		if (k == 1 || t[i] == 0) {
			freq[t[i]]--;
			ans += (freq[t[i]] * (freq[t[i]] - 1)) / 2;
		}
		else {
			ans += curr[t[i] * k];
			curr[t[i]] -= m[i];
		}
	}
	printf("%lld",ans);
}