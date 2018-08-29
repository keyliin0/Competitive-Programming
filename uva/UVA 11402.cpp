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

int  m, t, q;
int seg[4 * 1024004], v;
bool arr[4 * 1024004];
int lazy[4 * 1024004];

void process(int p, int s, int e) {
	if (lazy[p] == -1) return;
	if (lazy[p] == 1) seg[p] = e - s + 1;
	else if (lazy[p] == 2) seg[p] = 0;
	else seg[p] = e - s + 1 - seg[p];
	if (s != e) {
		if (lazy[p] == 1 || lazy[p] == 2) {
			lazy[2 * p] = lazy[p];
			lazy[2 * p + 1] = lazy[p];
		}
		else { // inverse part
			if (lazy[2 * p] == -1) lazy[2 * p] = lazy[p];
			else if (lazy[2 * p] == 1) lazy[2 * p] = 2;
			else if (lazy[2 * p] == 2) lazy[2 * p] = 1;
			else lazy[2 * p] = -1;
			if (lazy[2 * p + 1] == -1) lazy[2 * p + 1] = lazy[p];
			else if (lazy[2 * p + 1] == 1) lazy[2 * p + 1] = 2;
			else if (lazy[2 * p + 1] == 2) lazy[2 * p + 1] = 1;
			else lazy[2 * p + 1] = -1;
		}
	}
	lazy[p] = -1;
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
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int get(int p, int s, int e, int l, int r) {
	process(p, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[p];
	return get(2 * p, s, (s + e) / 2, l, r) + get(2 * p + 1, (s + e) / 2 + 1, e, l, r);
}

void build(int p, int s, int e) {
	if (s == e) {
		seg[p] = arr[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int main() {
	io;
	int tests;
	cin >> tests;
	loop(tt, 1, tests) {
		cout << "Case " << tt << ":" << endl;
		memset(seg, 0, sizeof seg);
		memset(lazy, -1, sizeof lazy);
		int n = 0;
		cin >> m;
		while (m--) {
			string in;
			cin >> t >> in;
			loop(j, 1, t) {
				loop(i, 0, in.size() - 1) {
					arr[n] = in[i] - '0';
					n++;
				}
			}
		}
		build(1, 0, n - 1);
		cin >> q;
		int cnt = 0;
		while (q--) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'F') v = 1;
			else if (c == 'E') v = 2;
			else v = 3;
			if (c == 'S') cout << "Q" << ++cnt << ": " << get(1, 0, n - 1, a, b) << endl;
			else update(1, 0, n - 1, a, b);
		}
	}
}