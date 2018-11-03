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

int n, d, a, b;
pair<ll, int> t[N];

int main() {
	scanf("%d%d%d%d",&n,&d,&a,&b);
	loop(i, 0, n - 1) {
		int x, y;
		scanf("%d%d",&x,&y);
		t[i].first = x * a + y * b;
		t[i].second = i + 1;
	}
	sort(t, t + n);
	vector<int> ans;
	loop(i, 0, n - 1) {
		if (t[i].first > d) break;
		ans.push_back(t[i].second);
		d -= t[i].first;
	}
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
}