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

int n, l, k;

pair<double, int> t[205];
int a[205];
double dp[205][205][205];

double solve(int i,int rem,int cnt) {
	if (i == n) return cnt >= l && rem >= 0;
	double &ret = dp[i][rem][cnt];
	if (ret == ret) return ret;
	ret = 0;
	if(rem > 0 || t[i].second != -1)
		ret += t[i].first * solve(i + 1, min(rem + t[i].second, 200), cnt + 1);
	ret += (1.0 - t[i].first) * solve(i + 1, rem, cnt);
	return ret;
}

bool compare(pair<double, int> &i, pair<double, int> &j) {
	return i.second > j.second;
}

int main() {
	scanf("%d%d%d",&n,&l,&k);
	loop(i, 0, n - 1) {
		scanf("%lf", &t[i].first);
		t[i].first /= 100.0;
	}
	loop(i, 0, n - 1) {
		scanf("%d", &t[i].second);
	}
	sort(t, t + n, compare);
	memset(dp, -1, sizeof dp);
	printf("%.6lf", solve(0, k, 0));
}