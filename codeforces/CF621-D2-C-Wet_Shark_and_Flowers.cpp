/* 
	we check the ith shark with i + 1 and we add the probability of getting a multiple of p to the ans
	to calculate the probability we first calculate the number of all possible pairs which are  (Ri - Li + 1) * (Rj - Lj + 1)
	then we calculate the pairs that gives us a multiple of P
	we know that to get a multiple of p either ith number must be a multiple of P or i + 1 a multiple of P or both
	so we find how multiples we can get from the ith item and i + 1 item and multiply them
	To do that we can calculate the number that are multiple of P from 1 to Li - 1 = x1 and 1 to Ri = x2
	And we have numbers of multiples between Li and Ri = x2 - x1
	finaly the current probability is number of pairs that gives us multiple of P / total number of pairs
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
pair<ll, ll> t[N];
ll p;

int main() {
	scanf("%d%lld", &n, &p);
	loop(i, 0, n - 1) {
		scanf("%lld%lld", &t[i].first, &t[i].second);
	}
	double ans = 0;
	for (int i = 0; i < n - 1; i++) {
		double x1 = (t[i].second / p) - ((t[i].first - 1) / p);
		double x2 = t[i + 1].second - t[i + 1].first + 1;
		double pairs = x1 * x2;
		double totalpairs = (t[i].second - t[i].first + 1) * x2;
		double pairs2 = (t[i].second - t[i].first + 1 - x1) * ((t[i + 1].second / p) - ((t[i + 1].first - 1) / p));
		 ans += (double)(pairs * 2000) / totalpairs;
		 ans += (double)(pairs2 * 2000) / totalpairs;
		//	printf("%d\n", pairs);
	}
	if (n >= 2) {
		double x1 = (t[n - 1].second / p) - ((t[n - 1].first - 1) / p);
		double x2 = t[0].second - t[0].first + 1;
		double pairs = x1 * x2;
		double totalpairs = (t[n - 1].second - t[n - 1].first + 1) * x2;
		double pairs2 = (t[n - 1].second - t[n - 1].first + 1 - x1) * ((t[0].second / p) - ((t[0].first - 1) / p));
		ans += (double) (pairs * 2000) / totalpairs;
		ans += (double)(pairs2 * 2000) / totalpairs;
	}
	printf("%0.6f", ans);
}