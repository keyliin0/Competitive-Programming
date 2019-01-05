/*
	it's easy to use normal dsu if there is no moving queries :
	if we use x as the root of n nodes then we removed x from it's component then we need to update all x's children which is slow
	for that create n other nodes which will be moved so we dont have to change children's root
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
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
int parent[N];
int nmb[N];
ll sum[N];

int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}

void un(int p, int q) {
	int a = find(p);
	int b = find(q);
	if (a != b) {
		nmb[b] += nmb[a];
		sum[b] += sum[a];
		parent[a] = b;
	}
}

void move(int p, int q) {
	int a = find(p);
	int b = find(q);
	if (a != b) {
		nmb[a]--;
		nmb[b]++;
		sum[a] -= p;
		sum[b] += p;
		parent[p] = b;
	}
}

int main() {
	while (cin >> n >> m) {
		int cnt = n + 1;
		loop(i, 1, n) {
			nmb[cnt] = 1;
			sum[cnt] = i;
			parent[i] = cnt;
			parent[cnt] = cnt;
			cnt++;
		}
		loop(i, 1, m) {
			int t, p, q;
			scanf("%d", &t);
			if (t == 1) {
				scanf("%d%d", &p, &q);
				un(p, q);
			}
			else if (t == 2) {
				scanf("%d%d", &p, &q);
				move(p, q);
			}
			else {
				scanf("%d", &p);
				int a = find(p);
				printf("%d %lld\n", nmb[a], sum[a]);
			}
		}
	}
}