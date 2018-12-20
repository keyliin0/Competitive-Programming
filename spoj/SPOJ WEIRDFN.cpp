/*
	use 2 priority queues, the first one store the first half of the sorted array and the other queue the other half 
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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll a, b, c;
int n;

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%lld%lld%lld%d", &a, &b, &c, &n);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		ll ans = 1;
		priority_queue<ll> q1, q2;
		if ((a + b * 2 + c) % mod >= 1) {
			q2.push(-((a + b * 2 + c) % mod));
			q1.push(1);
		}
		else {
			q1.push((a + b * 2 + c) % mod);
			q2.push(-1);
		}
		ans += (a + b * 2 + c) % mod;
		loop(i, 3, n) {
			ll u = q1.top();
			ll x = ((a * u) % mod + (b * i + c) % mod) % mod;
			ans += x;
			if (x > q1.top())  q2.push(-x);
			else q1.push(x);
			if (q2.size() > q1.size()) {
				q1.push(-q2.top());
				q2.pop();
			}
			else if(q1.size() > q2.size() + 1){
				q2.push(-q1.top());
				q1.pop();
			}
		}
		printf("%lld\n", ans);
	}
}