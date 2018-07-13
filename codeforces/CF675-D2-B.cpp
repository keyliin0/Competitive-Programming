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

int n, a, b, c, d;

int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x4 = i + a - d;
		int x5 = b + x4 - c;
		int x2 = d + x5 - a;
		if (x4 >= 1 && x5 >= 1 && x2 >= 1 && x4 <= n && x5 <= n && x2 <= n) ans++;
	}
	printf("%lld",(ll)ans * n);
}