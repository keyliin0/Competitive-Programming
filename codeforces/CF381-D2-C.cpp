/*
	store the moves and changing of the indices between each move
	then use binary search to find the element
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

vector<ll> sum;
pair<int, pair<int, int> > q[N];
int n, m;

int main() {
	scanf("%d", &n);
	sum.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x;
			scanf("%d", &x);
			sum[i + 1] = sum[i] + 1;
			q[i] = { type,{ x,-1 } };
		}
		else {
			int l, c;
			scanf("%d%d", &l, &c);
			sum[i + 1] = (ll)sum[i] + l * c;
			q[i] = { type,{ l,c } };
		}
	}
	scanf("%d", &m);
	while (m--) {
		ll idx;
		scanf("%lld", &idx);
		int p = 1;
		bool f = 1;
		while (q[p - 1].first != 1 || f){
			f = 0;
			p = lower_bound(sum.begin(), sum.end(), idx) - sum.begin();
			if (q[p - 1].first != 1) idx = (idx - sum[p - 1] - 1) % q[p - 1].second.first + 1;
		}
		printf("%d ",q[p - 1].second.first);
	}
}
