/*
	sort the nodes by decreasing order of their value 
	add each node one by one 
	when adding a node it will connect two seperate components
	the number of times the value will appear is the multiplication of size of the two components
*/
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
bool vis[N];
int p[N], sz[N];
 
int find(int u) {
	if (p[u] == u)
		return u;
	return p[u] = find(p[u]);
}
 
int main() {
	scanf("%d%d",&n,&m);
	g.resize(n + 1);
	vector<pair<ll, int> > v;
	loop(i, 1, n){
		ll x;
		scanf("%lld",&x);
		v.push_back({ x,i });
	}
	loop(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	loop(i, 1, n) {
		sz[i] = 1;
		p[i] = i;
	}
	ll sum = 0;
	loop(i, 0, n - 1) {
		int u = v[i].second;
		for (auto vv : g[u]) {
			if (!vis[vv]) continue;
			int a = u, b = vv;
			a = find(a);
			b = find(b);
			if (a != b) {
				sum += v[i].first * 1LL * (1LL * sz[b] * sz[a]) * 2;
				sz[b] += sz[a];
				p[a] = b;
			}
		}
		vis[u] = 1;
	}
	ll x = 1LL * n * (n - 1);
	//cout << sum << endl;
	printf("%.4lf",(double)sum / x);
}