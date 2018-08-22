/*
	- for the worst case query like (1 1 10^18) we only need to traverse log(10^18) nodes ~= 60 so we can build the graph for the costs using a map
	- to update and get the cost : we know that for two nodes v and u if we keep diving u and v by 2 we will find the LCA for these 2 nodes
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

int q;
map<pair<ll, ll>, ll> mp;

void update(ll u,ll v,ll x) {
	while (u != v) {
		if (u > v) {
			mp[{u, u / 2}] += x;
			mp[{u / 2,u}] += x;
			u /= 2;
		}
		else {
			mp[{v, v / 2}] += x;
			mp[{v / 2, v}] += x;
			v /= 2;
		}
	}
}

ll get(ll u,ll v) {
	ll cost = 0;
	while (u != v) {
		if (u > v) {
			cost += mp[{u, u / 2}];
			u /= 2;
		}
		else {
			cost += mp[{v, v / 2}];
			v /= 2;
		}
	}
	return cost;
}

int main() {
	scanf("%d",&q);
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t == 1) {
			ll u, v, x;
			scanf("%lld%lld%lld", &u, &v, &x);
			update(u, v, x);
		}
		else {
			ll u, v, x;
			scanf("%lld%lld", &u, &v);
			printf("%lld\n", get(u, v));
		}
	}
}