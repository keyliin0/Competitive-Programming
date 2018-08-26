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

int n, q;
int t[100005], seg[4 * 100005], input[100005];

void update(int p,int s,int e,int i) {
	if (s > i || e < i) return;
	if (s == e) {
		seg[p] = t[i];
		return;
	}
	update(2 * p, s, (s + e) / 2, i);
	update(2 * p + 1, (s + e) / 2 + 1, e, i);
	seg[p] = min(seg[2 * p], seg[2 * p + 1]);
}

int get(int p,int s,int e,int l,int r) {
	if (s >= l && e <= r) return seg[p];
	if (s > r || e < l) return oo;
	return min(get(2 * p, s, (s + e) / 2, l, r), get(2 * p + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
	scanf("%d%d", &n, &q);
	loop(i, 0, n - 1) {
		scanf("%d",&t[i]);
		update(1, 0, n - 1, i);
	}
	char s[33], num[10], aa[10];
	gets(num);
	while (q--) {
		gets(s);
		int size = strlen(s), inSize = 0, len = 0;
		while (sscanf(s + len, "%[^0123456789]%[^ ,)]%", aa, num) == 2) {
			input[inSize++] = stoi(num) - 1;
			len += strlen(num) + strlen(aa);
		}
		if (s[0] == 's') {
			for (int i = 1; i < inSize; i++) {
				swap(t[input[i]], t[input[i - 1]]);
			}
			for (int i = 0; i < inSize; i++) {
				update(1, 0, n - 1, input[i]);
			}
		}
		else printf("%d\n", get(1, 0, n - 1, input[0], input[1]));
	}
}