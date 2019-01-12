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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
pair<double,double> t[9];
int M[9];
double ans;

void solve(double v) {
	int cnt1 = 0, cnt0 = 0;
	loop(i, 0, n - 1) {
		cnt0 += M[i] == 0;
		cnt1 += M[i] == 1;
	}
	if (cnt0 > 1 || cnt1 == 0 || cnt0 == 0 && cnt1 <= 1) return;
	double p = v;
	loop(i, 0, n - 1) {
		if (M[i] == 0) {
			if (t[i].second <= v) return;
			p *= (t[i].second - max((double)v + 1, t[i].first) + 1) / (t[i].second - t[i].first + 1);
		}
		if (M[i] == 1) {
			if (v < t[i].first || v > t[i].second) return;
			p *= 1.0 / (t[i].second - t[i].first + 1);
		}
		if (M[i] == 2) {
			if (t[i].first >= v) return;
			p *= (min((double)v - 1, t[i].second) - t[i].first + 1) / (t[i].second - t[i].first + 1);
		}
	}
	ans += p;
}

void generate(int bit,double v) {
	if (bit == n) {
		solve(v);
		return;
	}
	for (int i = 0; i < 3; i++) {
		M[bit] = i;
		generate(bit + 1, v);
	}
}

int main() {
	scanf("%d", &n);
	double L = oo, R = -oo;
	loop(i, 0, n - 1) {
		scanf("%lf%lf", &t[i].first, &t[i].second);
		L = min(L, t[i].first);
		R = max(R, t[i].second);
	}
	loop(i, L, R) {
		generate(0, i);
	}
	printf("%.9lf", ans);
}