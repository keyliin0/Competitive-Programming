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

int n, m;
vector<vector<int> > g;
set<int> st;

void bfs(int u) {
	queue<int> q;
	st.erase(u);
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vector<int> tmp;
		for (auto it : st) {
			if (!binary_search(g[v].begin(), g[v].end(), it))
				tmp.push_back(it);
		}
		for (auto it : tmp) {
			st.erase(it);
			q.push(it);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	g.resize(n + 1);
	loop(i, 1, m) {
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	loop(i, 1, n) {
		sort(g[i].begin(), g[i].end());
		st.insert(i);
	}
	int cnt = 0;
	while (st.size()) {
		int u = *st.begin();
		bfs(u);
		cnt++;
	}
	printf("%d",cnt - 1);
}