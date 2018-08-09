/*
	the largest area will be the largest diffrence between 2 horizontal	lines and 2 vertical ones
	keep track of each diffrence in 2 multiset
	use binary search in each query to find the previous and next lines (H or V) of the current cut to update the diffrence
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

set<int> h, w;
multiset<int> mxh, mxw;
int n,hi,wi;

int main() {
	io;
	cin >> wi >> hi >> n;
	h.insert(0);
	h.insert(hi);
	w.insert(0);
	w.insert(wi);
	mxh.insert(hi);
	mxw.insert(wi);
	int m;
	char c;
	while (n--) {
		cin >> c >> m;
		if (c == 'H') {
			h.insert(m);
			auto it1 = h.upper_bound(m);
			auto it2 = it1;
			it2--;
			it2--;
			int r = *it1 - *it2;
			mxh.erase(mxh.find(r));
			int h1 = *it1 - m ;
			int h2 = m - *it2;
			mxh.insert(h1);
			mxh.insert(h2);
		}
		else {
			w.insert(m);
			auto it1 = w.upper_bound(m);
			auto it2 = it1;
			it2--;
			it2--;
			int r = *it1 - *it2;
			mxw.erase(mxw.find(r));
			int w1 = *it1 - m;
			int w2 = m - *it2;
			mxw.insert(w1);
			mxw.insert(w2);
		}
		ll ans = (ll)(*--mxw.end()) * (*--mxh.end());
		cout << ans << endl;
	}
}