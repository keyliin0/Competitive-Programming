/*
	use segment tree 
	each node holds two indices index of the first max and second max
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


int n;
int t[N];
pair<int,int> seg[4 * 100005];
int q;

bool compare(int i,int j) {
	return t[i] > t[j];
}


pair<int, int> get(int p,int s, int e,int l,int r) {
	if (s > r || e < l) return make_pair(-1,-1);
	if (s >= l && e <= r) return seg[p];
	pair<int, int> p1 = get(2 * p, s, (s + e) / 2, l, r);
	pair<int, int> p2 = get(2 * p + 1, (s + e) / 2 + 1, e, l, r);
	vector<int> v;
	if (p1.second != -1) v.push_back(p1.second);
	if (p2.second != -1) v.push_back(p2.second);
	if(p1.first != -1) v.push_back(p1.first);
	if(p2.first != -1) v.push_back(p2.first);
	sort(v.begin(), v.end(), compare);
	pair<int, int> p3;
	p3.first = v[0];
	if(v.size() > 1) p3.second = v[1];
	else p3.second = -1;
	return p3;
}

void update(int p,int s,int e,int i) {
	if (s == e) return;
	if (i <= (s + e) / 2) update(2 * p, s, (s + e) / 2, i);
	else update(2 * p + 1, (s + e) / 2 + 1, e, i);
	vector<int> v;
	pair<int, int> p1 = seg[2 * p];
	pair<int, int> p2 = seg[2 * p + 1];
	if (p1.second != -1) v.push_back(p1.second);
	if (p2.second != -1) v.push_back(p2.second);
	if (p1.first != -1) v.push_back(p1.first);
	if (p2.first != -1) v.push_back(p2.first);
	sort(v.begin(), v.end(), compare);
	seg[p].first = v[0];
	if (v.size() > 1) seg[p].second = v[1];
	else seg[p].second = -1;
}

void build(int p,int s,int e) {
	if (s == e) {
		seg[p].first = e;
		seg[p].second = -1;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	vector<int> v;
	if (seg[2 * p].second != -1) v.push_back(seg[2 * p].second);
	if (seg[2 * p + 1].second != -1) v.push_back(seg[2 * p + 1].second);
	v.push_back(seg[2 * p].first);
	v.push_back(seg[2 * p + 1].first);
	sort(v.begin(), v.end(), compare);
	seg[p].first = v[0];
	seg[p].second = v[1];
}

int main() {
	io;
	cin >> n;
	loop(i, 0, n - 1)
		cin >> t[i];
	build(1, 0, n - 1);
	cin >> q;
	while (q--) {
		char type;
		cin >> type;
		if (type == 'U') {
			int x, i;
			cin >> i >> x;
			t[i - 1] = x;
			update(1, 0, n - 1, i - 1);
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			pair<int, int> p = get(1, 0, n - 1, l, r);
			cout << t[p.first] + t[p.second] << endl;
		}
	}
}