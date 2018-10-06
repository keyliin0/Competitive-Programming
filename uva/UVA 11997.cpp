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

int k;
int ans[1000], t[1000];

int main() {
	while (scanf("%d", &k) != EOF) {
		loop(i, 0, k - 1)
			scanf("%d", &ans[i]);
		sort(ans, ans + k);
		loop(i, 1, k - 1) {
			loop(j, 0, k - 1) {
				scanf("%d",&t[j]);
			}
			sort(t, t + k);
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			loop(j, 0, k - 1) {
				q.push({ ans[j] + t[0] , 0 });
			}
			int idx = 0;
			while (!q.empty()) {
				pair<int, int> u = q.top();
				q.pop();
				ans[idx++] = u.first;
				if (u.second + 1 < k)
					q.push({ u.first - t[u.second] + t[u.second + 1] , u.second + 1 });
				if (idx >= k) break;
			}
		}
		printf("%d",ans[0]);
		loop(i, 1, k - 1) {
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
}