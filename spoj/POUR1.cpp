/*
	use BFS
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

int a, b, c;
map<pair<int, int>, bool> vis;

int main() {
	int tests;
	scanf("%d",&tests);
	while (tests--) {
		scanf("%d%d%d", &a, &b, &c);
		queue<pair<pair<int, int>, int> > q;
		q.push({ {0,0},0 });
		int ans = -1;
		vis.clear();
		while (!q.empty()) {
			int curra = q.front().first.first;
			int currb = q.front().first.second;
			int cost = q.front().second;
			if (curra == c || currb == c) {
				ans = cost;
				break;
			}
			q.pop();
			if (vis[{curra, currb}]) continue;
			vis[{curra, currb}] = 1;
			q.push({ { 0,currb },cost + 1 });
			q.push({ { curra,0 },cost + 1 });
			if (curra != a) q.push({ { a,currb },cost + 1 });
			if (currb != b) q.push({ { curra,b },cost + 1 });
			if(curra + currb <= a) q.push({ { curra + currb,0 },cost + 1 });
			else q.push({ { a,currb - (a - curra) },cost + 1 });
			if (curra + currb <= b) q.push({ { 0,curra + currb },cost + 1 });
			else q.push({ { curra - (b - currb),b },cost + 1 });
		}
		printf("%d\n",ans);
	}
}