/* 
	For every tree check how long will first and last trees be if current(We will name this height - len) 
	tree is unchanged. If it greater 0 increase a[len]
	Answer is n-max(a[len])
	also :
	Fixed the height of the first tree all the others are defined.
	So, for each tree you check which height of the first tree would keep it unchanged.
	Choose for the first tree the height that satisfies more trees
	Why the first tree is so special? First tree is most short.
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

int n;
int t[N], f[N];

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	loop(i, 0, n - 1) {
		int x = min(i, n - i - 1);
		if (t[i] - x > 0) f[t[i] - x]++;
	}
	int ans = 0;
	loop(i, 1, 1e6)
		ans = max(ans,f[i]);
	printf("%d",n - ans);
}