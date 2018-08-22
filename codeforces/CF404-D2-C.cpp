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

int n, k;
vector<pair<int,int> > ans;
vector<int> t[N];

void dfs(int u,int depth) {
	for (int i = 0; i < k - (depth != 1) && t[depth].size(); i++) {
		int v = t[depth].back();
		t[depth].pop_back();
		ans.push_back({ u,v });
		dfs(v, depth + 1);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	loop(i, 0, n - 1) {
		int a;
		scanf("%d", &a);
		t[a].push_back(i + 1);
	}
	if (t[0].size() != 1) {
		printf("-1");
		return 0;
	}
	dfs(t[0][0], 1);
	loop(i, 1, n)
		if (t[i].size()) {
			printf("-1");
			return 0;
		}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first,ans[i].second);
}