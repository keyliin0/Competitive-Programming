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


int f[N];
bool vis[N];
vector<set<int>> g;
int n;

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	loop(i, 1, n - 2) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		f[a]++;
		f[b]++;
		f[c]++;
		g[a].insert(b);
		g[a].insert(c);
		g[b].insert(a);
		g[b].insert(c);
		g[c].insert(a);
		g[c].insert(b);
	}
	int u;
	loop(i, 1, n) {
		if (f[i] == 1) {
			u = i;
			break;
		}
	}
	int r1, r;
	for (auto v : g[u]) {
		if (f[v] == 2) r1 = v;
	}
	int e;
	loop(i, 1, n) {
		if (f[i] == 1 && i != u) e = i;
		if (f[i] == 2 && i != r1) r = i;
	}
	int cnt = 1;
	vis[u] = 1;
	vis[e] = 1;
	vis[r] = 1;
	while (u != -1) {
		printf("%d ", u);
		vis[u] = 1;
		int x = -1;
		for (auto v : g[u]) {
			if (vis[v]) continue;
			f[v]--;
			if (f[v] <= 1) x = v;
		}
		u = x;
	}
	printf("%d %d",r , e);
}