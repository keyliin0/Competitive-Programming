/*
	since some ranges will never be used again we can split every range like :
	- [useless range] x [useless range] 
	- x [useless range]
	- [useless range] x 
	we can use an array to skip the useless part so we store the rightmost index of the first useful first range
	but still the index stored in a useless range may take us to another useless range and so on
	to avoid that we can update the array each sqrt(m) time
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

int ans[N], idx[N];
int n, m;

void update() {
	int curr = 0;
	for (int i = 1; i <= n; i++) {
		if (idx[i] == -1) curr = i;
		else idx[i] = curr;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	int root = sqrt(m);
	memset(idx, -1, sizeof idx);
	int cnt = 0;
	while (m--) {
		cnt++;
		if (cnt == root) {
			cnt = 0;
			update();
		}
		int l, r, x;
		scanf("%d%d%d",&l,&r,&x);
		for (int i = r; i > x; i--) {
			if (idx[i] == -1) {
				ans[i] = x;
				idx[i] = x;
			}
			else i = idx[i] + 1;
		}
		for (int i = x - 1; i >= l; i--) {
			if (idx[i] == -1) {
				ans[i] = x;
				if(idx[i - 1] == -1)
					idx[i] = l - 1;
				else idx[i] = idx[i - 1];
			}
			else i = idx[i] + 1;
		}
	}
	loop(i, 1, n)
		printf("%d ",ans[i]);
}