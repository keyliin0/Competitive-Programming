/* 
	we can use backtracking to generate all numbers with unique digits for minutes of length log7(m) + 1
	we generate all hours of length log7(n) + 1 with unique digits then we iterate over all minutes
	and check if we have unique digit for each string
	a brute force here may not seem possible at the first place but the max length of a number with
	unique digits from 0 to 6 is 7.
	since each digit must be unique we have 7! comb.but if we only count the number of strings with unique
	digit the number is too low so we can brute force with no problem
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

ll n, m;
int freq[10];
bool vis[10];
vector<string> ms;
ll mx = 0;
int ans;
int d;

void generate1(string s) {
	if (s.size() ==  d && mx >= stoll(s)) {
		if (stoll(s) > mx) return;
		ms.push_back(s);
		return;
	}
	for (int i = 0; i < 7; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		generate1(s + to_string(i));
		vis[i] = 0;
	}
}

void generate2(string s) {
	if (s.size() == d && mx >= stoll(s)) {
		for (int i = 0; i < ms.size(); i++) {
			bool add = 1;
			for (int k = 0; k < ms[i].size(); k++)
				for (int j = 0; j < s.size(); j++)
					if (s[j] == ms[i][k]) add = 0;
			ans += add;
		}
		return;
	}
	for (int i = 0; i < 7; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		generate2(s + to_string(i));
		vis[i] = 0;
	}
}

int main() {
	scanf("%lld%lld",&n,&m);
	n--;
	m--;
	ll tmp = m,p = 1;
	while (tmp != 0) {
		mx = mx + (tmp % 7) * p;
		p *= 10;
		tmp /= 7;
	}
	d = log10((mx == 0 ? 1 : mx)) + 1;
	generate1("");
	mx = 0, tmp = n,p = 1;
	while (tmp != 0) {
		mx = mx + (tmp % 7) * p;
		p *= 10;
		tmp /= 7;
	}
	d = log10((mx == 0 ? 1 : mx)) + 1;
	generate2("");
	cout << ans;
}