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

int n, m;
vector<pair<int, pair<int, int>> > e;
pair<int, int> ans[N];

bool compare(pair<int, pair<int, int> > i, pair<int, pair<int, int> > j) {
	if (i.first == j.first) return i.second.second > j.second.second;
	return i.first < j.first;
}

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		e.push_back({ a,{i,b} });
	}
	sort(e.begin(), e.end(), compare);
	priority_queue<pair<int, pair<int, int>> > q;
	int total = 0, curr = 1;
	loop(i, 0, m - 1) {
		if (e[i].second.second) {
			curr++;
			int cnt = 2;
			for (int j = 0; j < i && total < m; j++)
				if (e[j].second.second) {
					q.push({ -(e[j].first) , {curr,cnt} });
					cnt++;
					total++;
				}
			ans[e[i].second.first] = make_pair(1, curr);
		}
		else {
			if (!q.size()) {
				printf("-1");
				return 0;
			}
			int c = -q.top().first;
			if (c > e[i].first) {
				printf("-1");
				return 0;
			}
			ans[e[i].second.first] = make_pair(q.top().second.first, q.top().second.second);
			q.pop();
		}
	}
	loop(i, 1, m)
		printf("%d %d\n", ans[i].first, ans[i].second);
}