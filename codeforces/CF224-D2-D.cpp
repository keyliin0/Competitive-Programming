/*
	for the current character check the longest subsequence it can make from the left and right 
	if it's < length string t then the ans is no
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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int R[N], L[N];
string s, t;

int main() {
	cin >> s >> t;
	if (t.size() > s.size()) {
		cout << "No";
		return 0;
	}
	int curr[26];
	memset(curr, 0, sizeof curr);
	for (int i = s.size() - 1, cnt = t.size() - 1; i >= 0; i--) {
		if (cnt == -1) {
			R[i] = curr[s[i] - 'a'];
			continue;
		}
		if (s[i] == t[cnt]) {
			curr[s[i] - 'a'] = t.size() - cnt;
			cnt--;
			R[i] = curr[s[i] - 'a'];
		}
		else R[i] = curr[s[i] - 'a'];
	}
	memset(curr, 0, sizeof curr);
	bool yes = 1;
	for (int i = 0, cnt = 0; i < s.size(); i++) {
		if (cnt == t.size()) {
			L[i] = curr[s[i] - 'a'];
		}
		else {
			if (s[i] == t[cnt]) {
				curr[s[i] - 'a'] = cnt + 1;
				cnt++;
				L[i] = curr[s[i] - 'a'];
			}
			else L[i] = curr[s[i] - 'a'];
		}
		if (R[i] + L[i] < t.size()) yes = 0;
	}
	cout << (yes ? "Yes" : "No");
}