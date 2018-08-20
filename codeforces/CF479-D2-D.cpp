/*
	3 possible cases :
	- ans is 0 if you can do the measurement for boys and girls without adding a point
	- ans is 1 if cant do the measurement for either the boy or the girl 
		another case here is if we can add only one point to measure the distance for both of them (instead of adding 2 points)
	- ans is 2 if we cant do measurement for both with adding 1 point
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

vector<ll> v;
int n;
ll l, x, y;
map<ll, bool> mp_boy,mp_girl;

int main() {
	scanf("%d%lld%lld%lld", &n, &l, &x, &y);
	loop(i, 0, n - 1) {
		ll a;
		scanf("%lld", &a);
		v.push_back(a);
	}
	bool girl = 0, boy = 0, same = 0;
	ll ans;
	loop(i, 0, n - 1) {
		if (x + v[i] <= l) {
			if (mp_boy[x + v[i]]) same = 1,ans = x  + v[i];
			mp_girl[x + v[i]] = 1;
			if (binary_search(v.begin(), v.end(), x + v[i])) girl = 1;
		}
		if (y + v[i] <= l) {
			if (mp_girl[y + v[i]]) same = 1,ans = y  + v[i];
			mp_boy[y + v[i]] = 1;
			if (binary_search(v.begin(), v.end(), y + v[i])) boy = 1;
		}
		if (v[i] - x >= 0) {
			if (mp_boy[v[i] - x]) same = 1, ans = v[i] - x;
			mp_girl[v[i] - x] = 1;
		}
		if (v[i] - y >= 0) {
			if (mp_girl[v[i] - y]) same = 1, ans = v[i] - y;
			mp_boy[v[i] - y] = 1;
		}
	}
	vector<ll> t;
	if (!girl) t.push_back(x);
	if (!boy) t.push_back(y);
	if (boy && girl) {
		printf("0");
		return 0;
	}
	if (same) printf("1\n%lld",ans);
	else {
		printf("%d\n", t.size());
		for (int i = 0; i < t.size(); i++)
			printf("%lld ",t[i]);
	}
}