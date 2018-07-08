/*
	use the formula http://zobayer.blogspot.com/2009/11/volume-of-irregular-tetrahedron.html
	or https://keisan.casio.com/exec/system/1329962711
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

double u, v, w, W, V, U;

int main() {
	int tests;
	cin >> tests;
	bool line = 0;
	while (tests--) {
		if (line) cout << endl;
		line = 1;
		cin >> u >> v >> w >> V >> W >> U;
		double uu, vv, ww;
		uu = v * v + w * w - U * U;
		vv = w * w + u * u - V * V;
		ww = u * u + v * v - W * W;
		double ans = sqrt(4 * u * u * v * v * w * w - u * u * uu * uu - v * v * vv * vv - w * w * ww * ww + uu * vv  * ww) / 12.0;
		printf("%.4lf\n", ans);
	}
}