/*
	write normal segment tree 
	if we get a query like L > R
	then update or get L to n and 0 to R
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

int n, q;
ll seg[4 * 200005], lazy[4 * 200005], v;
int t[4];

void process(int p, int s, int e) {
	seg[p] += lazy[p];
	if (s != e) {
		lazy[2 * p] += lazy[p];
		lazy[2 * p + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int s, int e, int l, int r) {
	process(p, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[p] = v;
		process(p, s, e);
		return;
	}
	update(2 * p, s, (s + e) / 2, l, r);
	update(2 * p + 1, (s + e) / 2 + 1, e, l, r);
	seg[p] = min(seg[2 * p], seg[2 * p + 1]);
}

ll get(int p, int s, int e, int l, int r) {
	process(p, s, e);
	if (s >= l && e <= r) return seg[p];
	if (s > r || e < l) return (ll)1e18;
	return min(get(2 * p, s, (s + e) / 2, l, r), get(2 * p + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
	io;
	cin >> n;
	loop(i, 0, n - 1) {
		cin >> v;
		update(1, 0, n - 1, i, i);
	}
	cin >> q;
	cin.ignore();
	string line;
	while (q--) {
		getline(cin, line);
		istringstream iss(line);
		int k = 0;
		while (iss >> t[k]) k++;
		int l = t[0], r = t[1];
		if (k == 2) {
			ll mn1 = 1e18, mn2 = 1e18;
			if (l > r) {
				mn1 = get(1, 0, n - 1, l, n - 1);
				mn2 = get(1, 0, n - 1, 0, r);
			}
			else mn1 = get(1, 0, n - 1, l, r);
			cout << min(mn1, mn2) << endl;
		}
		else {
			v = t[2];
			if (l > r) {
				update(1, 0, n - 1, l, n - 1);
				update(1, 0, n - 1, 0, r);
			}
			else update(1, 0, n - 1, l, r);
		}
	}
}