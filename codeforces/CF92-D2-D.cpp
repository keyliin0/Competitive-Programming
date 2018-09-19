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

int n;
pair<int, int> t[N];
int ans[N];

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%d",&t[i].first);
		t[i].second = i;
	}
	sort(t, t + n);
	int mx_idx = -2, tmp = -1;
	loop(i, 0, n - 1) {
		tmp = max(tmp, t[i].second);
		ans[t[i].second] = mx_idx - t[i].second - 1 >= 0 ? mx_idx - t[i].second - 1 : -1;
		if (t[i].first != t[i + 1].first) {
			mx_idx = tmp;
		}
	}
	loop(i, 0, n - 1)
		printf("%d ", ans[i]);
}