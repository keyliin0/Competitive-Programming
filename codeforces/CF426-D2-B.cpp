/*
	we check every number of rows of b 
	number of rows of b must be equal to n when we multiply it by 2 several times
	we can build the matrix b and apply mirrorings on it until it's the same size with A and check if they are equal
	but we can optimize that,if we trace the mirroring operation we see that the initial R rows of b will be reversed and after another operation they will
	be go back to the initial state and so on
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

int n,m;
int g[105][105];

bool check(int c) {
	int tmp = c;
	while (tmp < n) tmp *= 2;
	int s = 1, r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r == c) {
				r--;
				s = -1;
			}
			if (r == -1) {
				r++;
				s = 1;
			}
			if (g[r][j] != g[i][j]) return 0;
		}
		r += s;
	}
	return tmp == n;
}

int main() {
	scanf("%d%d",&n,&m);
	if (n % 2 != 0) {
		printf("%d",n);
		return 0;
	}
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			scanf("%d",&g[i][j]);
	int ans = n,c = n;
	c /= 2;
	while (c > 0) {
		if (check(c)) ans = c;
		c /= 2;
	}
	printf("%d",ans);
}