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

pair<double, double> t[50001];
int n;


bool compare(pair<double, double> i, pair<double, double> j) {
	return i.first * i.second * (1.0 - j.second) > j.first * j.second * (1.0 - i.second);
}

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		scanf("%lf%lf", &t[i].first, &t[i].second);
		t[i].second /= 100.0;
	}
	sort(t, t + n, compare);
	double ans = 0, curr = 0;
	loop(i, 0, n - 1) {
		ans += t[i].first + (curr * (1.0 - t[i].second));
		curr += t[i].first * t[i].second;
	}
	printf("%.9lf",ans);
}