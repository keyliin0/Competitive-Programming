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

int n;
int seg[200005 * 4];

void update(int p, int s, int e, int v, int i) {
	if (s == e) {
		 seg[p] = v;
		return;
	}
	if (i <= (s + e) / 2) update(p * 2, s, (s + e) / 2, v, i);
	else update(p * 2 + 1, (s + e) / 2 + 1, e, v, i);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int get(int p, int s, int e, int l, int r) {
	if (s >= l && e <= r) return seg[p];
	if (s > r || e < l) return 0;
	return get(p * 2, s, (s + e) / 2, l, r) + get(p * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	int test = 0;
	while (1) {
		scanf("%d",&n);
		if (n == 0) return 0;
		if (test) printf("\n");
		test++;
		printf("Case %d:\n", test);
		loop(i, 0, n - 1) {
			int x;
			scanf("%d",&x);
			update(1, 0, n - 1, x, i);
		}
		string c;
		while (1) {
			cin >> c;
			if (c[0] == 'M') {
				int l, r;
				scanf("%d%d",&l,&r);
				l--;
				r--;
				printf("%d\n", get(1, 0, n - 1, l, r));
			}
			else if (c[0] == 'S') {
				int i, v;
				scanf("%d%d",&i,&v);
				i--;
				update(1, 0, n - 1, v, i);
			}
			else break;
		}
	}
}