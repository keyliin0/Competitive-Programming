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

pair<int, int> seg[4 * 30005];
char t[N];
int n, q;

void update(int p, int s, int e, int i) {
	if (s == e) {
		swap(seg[p].first, seg[p].second);
		return;
	}
	if (i <= (s + e) / 2) update(2 * p, s, (s + e) / 2, i);
	else update(2 * p + 1, (s + e) / 2 + 1, e, i);
	seg[p].first = seg[2 * p + 1].first;
	seg[p].second = seg[2 * p].second;
	int diff = seg[2 * p].first - seg[2 * p + 1].second;
	if (diff >= 0)
		seg[p].first += diff;
	else seg[p].second -= diff;
}

void build(int p, int s, int e) {
	if (s == e) {
		seg[p].first = t[e] == '(';
		seg[p].second = t[e] == ')';
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p].first = seg[2 * p + 1].first; // we know that the we cannot close the unclosed open brackets to the right
	seg[p].second = seg[2 * p].second; // same goes for the close brackets to the left
	int diff = seg[2 * p].first - seg[2 * p + 1].second; // merging
	if (diff >= 0)
		seg[p].first += diff;
	else seg[p].second -= diff;
}


int main() {
	io;
	loop(test, 1, 10) {
		cout << "Test " << test << ":" << endl;
		cin >> n;
		loop(i, 0, n - 1)
			cin >> t[i];
		cin >> q;
		build(1, 0, n - 1);
		while (q--) {
			int i;
			cin >> i;
			if (i) {
				i--;
				update(1, 0, n - 1, i);
			}
			else cout << (seg[1].first + seg[1].second == 0 ? "YES" : "NO") << endl;
		}
	}
}
