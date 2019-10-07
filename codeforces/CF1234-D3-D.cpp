#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

bool EMPTY_ARRAY[26];
string S;
bool seg[400005][26];
int l, r;
int x;

void update(int p, int s, int e) {
	if (s == e) {
		loop(i, 0, 25)
			seg[p][i] = 0;
		seg[p][S[s] - 'a'] = 1;
		return;
	}
	if(x <= (s + e) / 2) update(2 * p, s, (s + e) / 2);
	else update(2 * p + 1, (s + e) / 2 + 1, e);
	loop(i, 0, 25)
		seg[p][i] = seg[2 * p][i] || seg[2 * p + 1][i];
}

bool * get(int p, int s, int e) {
	if (s > r || e < l) {
		return EMPTY_ARRAY;
	}
	if (s >= l && e <= r) return seg[p];
	bool * left = get(2 * p, s, (s + e) / 2);
	bool * right = get(2 * p + 1, (s + e) / 2 + 1, e);
	bool * ret = new bool[26];
	loop(i, 0, 25)
		ret[i] = left[i] || right[i];
	return ret;
}

void build(int p, int s, int e) {
	if (s == e) {
		seg[p][S[s] - 'a'] = 1;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	loop(i, 0, 25)
		seg[p][i] = seg[2 * p][i] || seg[2 * p + 1][i];
}

int q;

int main() {
	io;
	cin >> S >> q;
	build(1, 0, S.size() - 1);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			char c;
			cin >> x >> c;
			x--;
			S[x] = c;
			update(1, 0, S.size() - 1);
		}
		else {
			cin >> l >> r;
			l--;
			r--;
			bool * res = get(1, 0, S.size() - 1);
			int ans = 0;
			loop(i, 0, 25)
				if (res[i])
					ans++;
			cout << ans << "\n";
		}
	}
}