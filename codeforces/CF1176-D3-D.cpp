#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1e6;

bool prime[N];
vector<int> v;
int n;
int t[N];
int f[N];

void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
	for (i = 2; i <= n; i++)
		if (prime[i] == true)
			v.push_back(i);
}

int main() {
	v.push_back(0);
	generateprime(2750135);
	scanf("%d",&n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &t[i]);
	sort(t, t + 2 * n);
	reverse(t, t + 2 * n);
	vector<int> ans;
	for (int i = 0; i < 2 * n; i++) {
		if (prime[t[i]]) continue;
		if (f[t[i]]) {
			f[t[i]]--;
			continue;
		}
		int mx = -1e9;
		for (int j = 2; j * j <= t[i]; j++) {
			if (t[i] % j == 0) {
				mx = max(mx, j);
				if (t[i] / j != j) mx = max(mx, t[i] / j);
			}
		}
		f[mx]++;
		ans.push_back(t[i]);
	}
	reverse(t, t + 2 * n);


	for (int i = 0; i < 2 * n; i++) {
		if (!prime[t[i]]) continue;
		if (f[t[i]]) {
			f[t[i]]--;
			continue;
		}
		f[v[t[i]]]++;
		ans.push_back(t[i]);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
}