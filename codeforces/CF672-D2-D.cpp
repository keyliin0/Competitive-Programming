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
ll k, t[N];

ll check1(ll m) {
	ll cnt = 0;
	loop(i, 0, n - 1)
		cnt += max((ll)0, m - t[i]);
	return cnt;
}

ll check2(ll m) {
	ll cnt = 0;
	loop(i, 0, n - 1)
		cnt += max((ll)0,t[i] - m);
	return cnt;
}

int main() {
	scanf("%d%lld",&n,&k);
	loop(i, 0, n - 1)
		scanf("%lld",&t[i]);
	sort(t, t + n);
	ll l = 0, r = 1e10, mn, cnt;
	while (l <= r) {
		ll m = (l + r) / 2;
		ll curr = check1(m);
		if (curr <= k) {
			mn = m;
			cnt = curr;
			l = m + 1;
		}
		else r = m - 1;
	}
	loop(i, 0, n - 1)
		t[i] = max(mn, t[i]);
	for (int i = 0; i < k - cnt;i++)
		t[i]++;
	l = 0, r = 1e10,cnt = 0;
	ll mx;
	while (l <= r) {
		ll m = (l + r) / 2;
		ll curr = check2(m);
		if (curr <= k) {
			cnt = curr;
			mx = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	loop(i, 0, n - 1)
		t[i] = min(mx, t[i]);
	sort(t, t + n);
	reverse(t, t + n);
	for (int i = 0; i < k - cnt; i++)
		t[i]--;
	loop(i, 0, n - 1) {
		mx = max(mx, t[i]);
		mn = min(mn, t[i]);
	}
	printf("%lld", mx - mn);
}