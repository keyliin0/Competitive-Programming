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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, q;
double s, a, b;
ll sum[N];
vector<pair<double, double> > v;

double get(int idx,double x,double y) {
	double slope;
	if(idx == 0) slope = (x - v[idx].first) / y;
	else slope = (x - v[idx].second) / y;
	double bs = y - slope * x;
	return y / bs + slope;
}

int main() {
	scanf("%lf%lf%lf%d", &s, &a, &b ,&n);
	loop(i, 0, n - 1) {
		double l, r;
		scanf("%lf%lf", &l, &r);
		v.push_back({ l,r });
		sum[i] = 1ll * (r - l) + (i > 0 ? sum[i - 1] : 0);
	}
	scanf("%d", &q);
	s = s * -1.0;
	while (q--) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		double ratio = (double)(y + s) / y;
		//double x1 = max(get(0, x, y), 1.0* a);
		//double x2 = min(get(n - 1, x, y), 1.0* b);
		double x1 = x - ((1.0*y*(x - a)) / (1.0*y + s));
		double x2 = x + ((1.0*y*(b - x)) / (1.0*y + s));
		int l = lower_bound(v.begin(), v.end(), make_pair(x1, -1.0)) - v.begin();
		int r = lower_bound(v.begin(), v.end(), make_pair(x2, -1.0)) - v.begin() - 1;
		while (r >= 0 && v[r].second > x2) r--;
		double total = 0;
		if (l <= r && l >= 0 && r < v.size()) total += sum[r] - (l ? sum[l - 1] : 0);
		if (--l >= 0) total += max(0.0, min(x2, v[l].second) - x1);
		if (++r >= 0 && r < v.size() && l != r) total += max(0.0, x2 - v[r].first);
		printf("%.6lf\n",total * ratio);
	}
}