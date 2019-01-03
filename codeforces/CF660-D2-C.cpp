#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[300005],pre[300005];
int n, k;

bool can(int m) {
	for (int i = 1; i + m - 1 <= n; i++)
		if (m - (pre[i + m - 1] - pre[i - 1]) <= k)
			return 1;
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d",&t[i]);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + t[i];
	}
	int l = 1, r = n, len = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (can(m)) {
			len = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	for (int i = 1; i + len - 1 <= n && len; i++) {
		if (len - (pre[i + len - 1] - pre[i - 1]) <= k) {
			for (int j = i; j <= i + len - 1;j++)
				t[j] = 1;
			break;
		}
	}
	printf("%d\n",len);
	for (int i = 1; i <= n; i++)
		printf("%d ",t[i]);
}