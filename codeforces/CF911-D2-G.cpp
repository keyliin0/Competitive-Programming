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
#define logg2  0.30102999566398119521373889472449L
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

int const MAX = 200010;
short seg[4 * MAX][102];
int n, q, v, x, idx;
int t[MAX];


void update(int p, int s, int e) {
	if (s == e) {
		seg[p][v] = x;
		return;
	}
	if(idx <= (s + e) / 2) update(2 * p, s, (s + e) / 2);
	else update(2 * p + 1, (s + e) / 2 + 1, e);
	for (int i = 1; i <= 100; i++)
		seg[p][i] = seg[2 * p + 1][seg[2 * p][i]];
}


void build(int p, int s, int e) {
	if (s == e) {
		for (int i = 1; i <= 100; i++)
			seg[p][i] = i;
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	for (int i = 1; i <= 100; i++)
		seg[p][i] = i;
}

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1)
		scanf("%d", &t[i]);
	scanf("%d", &q);
	vector<vector<pair<int,pair<int,int> > > > Q;
	Q.resize(n + 1);
	loop(qq,0,q - 1) {
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		l--;
		r--;
		Q[l].push_back({ qq,{x,y} });
		Q[r + 1].push_back({ qq,{x,x} });
	}
	build(1, 0, q - 1);
	loop(i, 0, n - 1) {
		for (int j = 0; j < Q[i].size(); j++) {
			v = Q[i][j].second.first;
			x = Q[i][j].second.second;
			idx = Q[i][j].first;
			update(1, 0, q - 1);
		}
		printf("%d ", seg[1][t[i]]);
	}
}