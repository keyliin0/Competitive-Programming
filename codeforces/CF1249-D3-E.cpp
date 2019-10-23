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

int n, c;
int cst[200005][2];
int a[N], b[N];

int main() {
	scanf("%d%d",&n,&c);
	loop(i, 1, n - 1)
		scanf("%d", &a[i]);
	loop(i, 1, n - 1)
		scanf("%d", &b[i]);
	loop(i, 1, n) {
		cst[i][0] = cst[i][1] = oo;
	}
	priority_queue<pair<int, pair<int, int> >> q;
	cst[1][0] = cst[1][1] = 0;
	q.push({ 0,{1,0} });
	while (!q.empty()) {
		int u = q.top().second.first;
		int f = q.top().second.second;
		int curr = -q.top().first;
		q.pop();
		if (cst[u][f] < curr) continue;
		if (u == n) continue;
		if (f) {
			if (curr + b[u] < cst[u + 1][1]) {
				cst[u + 1][1] = curr + b[u];
				q.push({ -cst[u + 1][1] ,{u + 1,1} });
			}
			if (curr + a[u] < cst[u + 1][0]) {
				cst[u + 1][0] = curr + a[u];
				q.push({ -cst[u + 1][0] ,{u + 1,0} });
			}
		}
		else {
			if (curr + b[u] + c < cst[u + 1][1]) {
				cst[u + 1][1] = curr + b[u] + c;
				q.push({ -cst[u + 1][1] ,{u + 1,1} });
			}
			if (curr + a[u] < cst[u + 1][0]) {
				cst[u + 1][0] = curr + a[u];
				q.push({ -cst[u + 1][0] ,{u + 1,0} });
			}
		}
	}
	loop(i, 1, n)
		printf("%d ", min(cst[i][0], cst[i][1]));
}