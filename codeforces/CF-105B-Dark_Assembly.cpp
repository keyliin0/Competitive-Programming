/* 
	the problem can be divided into two parts
	the first part is to distribute k candy in an optimal way
	this can be done by a brute force since k < 8
	the second part is to calculate the probability of each case
	we can use a mask 0 mean a no and 1 yes
	the probability will be pi if vote is yes and 1 - pi otherwise
	if less than or equal n / 2 voted no then we must multiplay it by a / (a + sum)
	where sum is the sum of levels of who voted no
	we add each case of mask to the current ans
	and finally the ans will be the biggest value
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

int a, k, n;
pair<int, int> t[10];
double ans = 0;

void calc() {
	double curr = 0;
	for (int i = 0; i < (1 << n); i++) {
		double p1 = 1, p2 = 1;
		int cnt = 0;
		int sum = 0;
		bool f = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				p1 *= (double)t[j].second / 100, cnt++;
			else {
				sum += t[j].first;
				double tmp = (double)t[j].second / 100;
				p2 *= (1.0 - tmp);
			}
		}
		if (f) continue;
		double p3 = (double)a / (a + sum);
		if (2 * cnt > n) curr += p1 * p2;
		else curr += p1 * p2 * p3;
	}
	ans = max(curr, ans);
}

void solve(int i, int rem) {
	if (rem == 0 || i == n) {
		calc();
		return;
	}
	for (int j = 0; j <= rem; j++) {
		if (t[i].second + j * 10 > 100) break;
		t[i].second += j * 10;
		solve(i + 1, rem - j);
		t[i].second -= j * 10;
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &a);
	loop(i, 0, n - 1)
		scanf("%d%d", &t[i].first, &t[i].second);
	solve(0, k);
	printf("%.9f", ans);
}
