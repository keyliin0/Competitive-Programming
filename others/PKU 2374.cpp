/*
	use dp since col can take 2 values left or right of last segment
*/
#include <stdio.h>
#include <map>
#include <algorithm>
#include <complex>
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, s;
pair<int, int> t[N];
map<pair<int, int>, int > dp;

int solve(int row,int col) {
	if (row == n) return abs(col);
	int &ret = dp[make_pair(row, col)];
	if (ret) return ret;
	ret = oo;
	int left = abs(t[row].first - col);
	int right = abs(t[row].second - col);
	for (int i = row + 1; i <= n; i++) {
		if (t[i].first <= t[row].first && t[i].second >= t[row].first) {
			ret = min(ret, left + solve(i, t[row].first));
			break;
		}
	}
	for (int i = row + 1; i <= n; i++) {
		if (t[i].first <= t[row].second && t[i].second >= t[row].second) {
			ret = min(ret, right + solve(i, t[row].second));
			break;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d",&n,&s);
	loop(i, 0, n - 1)
		scanf("%d%d",&t[n - i - 1].first,&t[n - i - 1].second);
	t[n].first = -oo;
	t[n].second = oo;
	int ans = solve(0, s);
	printf("%d",ans);
}