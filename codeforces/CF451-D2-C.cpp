/*
	there are 4 cases
	w1 > w2 & w2 > 3 or w1 < w2 & w2 > w3 or w1 > w2 & w2 < w3 or w1 < w2 & w2 < w3
	w1,w2 and w3 means the win of each team
	if we try to solve the equation of the first case we have:
		w1 - w2 = d1
		w2 - w3 = d2
		we know that w1 + w2 + w3 = k
		let's sum the first two equations
		w1 - w3 = w1 + d2
		then sum the third equation with the first one we have :
		2w1 + w3 = k + d1
		and finally sum the last 2 equations
		3w1 = k + 2 d1 + d2
	since we have w1 we can now find other variables
	now we know w1,w2,w3 we must check if we can increase the 2 minimum vars to equal the max one
	if we can do that we have to check if we can keep these vars equal to the end of the tournament
	we can solve the other cases while changing the sign of d1 and d2
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

ll n, k, d1, d2;

bool check(ll d1,ll d2) {
	ll w1 = (k + 2 * d1 + d2) / 3;
	ll w2 = w1 - d1;
	ll w3 = w2 - d2;
	ll mx = max(w1, max(w2, w3));
	ll r = mx - w1 + mx - w2 + mx - w3;
	return (n - k - r) % 3 == 0 && r <= n - k && w1 >= 0 && w2>=0 && w3>=0;
}

int main() {
	int tests;
	scanf("%d",&tests);
	while (tests--) {
		scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
		bool yes = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				yes |= check((i == 1 ? -d1 : d1), (j == 1 ? -d2 : d2));
		if (yes && n % 3 == 0) printf("yes\n");
		else printf("no\n");
	}
}