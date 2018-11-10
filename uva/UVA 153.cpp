/*	
	count the number of permutations < than the given string
	to avoid overflow of factorial use prime fact
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

string s;
int cnt[50];
ll ans = 0;
vector<int> factors[33];

void solve(int idx) {
	if (idx == s.size()) return;
	loop(i, 0, 25) {
		if (cnt[i] == 0) continue;
		cnt[i]--;
		if (s[idx] - 'a' == i) {
			solve(idx + 1);
			return;
		}
		ll curr = 1;
		int A[40];
		memset(A, 0, sizeof A);
		for (int j = 0; j < s.size() - idx; j++)
			for (int k = 0; k < factors[j].size(); k++)
				A[factors[j][k]]++;
		for (int j = 0; j < 26; j++)
			for (int u = 1; u <= cnt[j]; u++)
				for (int k = 0; k < factors[u].size(); k++)
					A[factors[u][k]]--;
		loop(j, 1, 31)
			loop(k, 1, A[j])
				curr *= (ll)j;
		ans += curr;
		cnt[i]++;
	}
}

int main() {
	factors[0].push_back(1);
	factors[1].push_back(1);
	loop(i, 2, 30) {
		factors[i].push_back(1);
		int curr = i;
		for(int j = 2;j <= curr / j;j++) {
			while (curr % j == 0) {
				factors[i].push_back(j);
				curr /= j;
			}
		}
		if (curr != 1) factors[i].push_back(curr);
	}
	while (1) {
		cin >> s;
		if (s == "#") return 0;
		memset(cnt, 0, sizeof cnt);
		loop(i, 0, s.size() - 1)
			cnt[s[i] - 'a']++;
		ans = 0;
		solve(0);
		cout << setw(10) << ans + 1 << "\n";
	}
}