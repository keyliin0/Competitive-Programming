/*
	segment tree + lazy propagation
	lazy contain 1 0 or -1 
	-1 means we dont need to update
	0 and 1 if the segment have prime number or not
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

int lazy[4 * 10005], seg[4 * 10005];
bool prime[N];
int n, q, l, r, v;

void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
}

void process(int p,int s,int e) {
	if (lazy[p] == -1) return;
	seg[p] = (e - s + 1) * lazy[p];
	if (s != e) {
		lazy[2 * p] = lazy[p];
		lazy[2 * p + 1] = lazy[p];
	}
	lazy[p] = -1;
}

void update(int p,int s,int e) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] = prime[v];
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2);
	update(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int get(int p, int s, int e) {
	process(p, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[p];
	return get(2 * p, s, (s + e) / 2) + get(2 * p + 1, (s + e) / 2 + 1, e);
}

int main() {
	int t;
	scanf("%d",&t);
	generateprime(1e6);
	loop(test, 1, t) {
		printf("Case %d:\n",test);
		scanf("%d%d",&n,&q);
		loop(i, 0, n - 1) {
			scanf("%d", &v);
			l = i , r = i ;
			update(1, 0, n - 1);
		}
		while (q--) {
			int type;
			scanf("%d%d%d",&type,&l,&r);
			l--;
			r--;
			if (type) {
				printf("%d\n", get(1, 0, n - 1));
			}
			else {
				scanf("%d",&v);
				update(1, 0, n - 1);
			}
		}
	}
}