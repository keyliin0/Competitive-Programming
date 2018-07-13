/* 
	
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
struct point{
	int x, y, z, d;
};
typedef point pt;
 
pt t[2005];
int n;
 
int main() {
	while (1) {
		scanf("%d",&n);
		if (n == 0) return 0;
		loop(i, 0, n - 1) {
			scanf("%d%d%d%d",&t[i].x,&t[i].y,&t[i].z,&t[i].d);
		}
		int lx = t[0].x, rx = t[0].x + t[0].d, ly = t[0].y, ry = t[0].y + t[0].d, lz = t[0].z, rz = t[0].z + t[0].d;
		loop(i, 1, n - 1) {
			lx = max(lx,t[i].x);
			ly = max(ly,t[i].y);
			lz = max(lz,t[i].z);
			rx = min(rx,t[i].x + t[i].d);
			ry = min(ry,t[i].y + t[i].d);
			rz = min(rz,t[i].z + t[i].d);
		}
		if (lx > rx || lz > rz || ly > ry) {
			printf("0\n");
		}
		else{
			ll ans = (ll)(rx - lx) *(ry - ly) * (rz - lz);
			printf("%lld\n",ans);
		}
	}
}