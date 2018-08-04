/*
	Let s be the string given in input and t a string which maximizes ρ(s, t).
	Take one character (let's call it c) from t. By shifting s and t in all possible ways,
	c is going to be at the same position as s[i] exactly n times (for i = 0, n — 1).
	So, the character c adds to ρ(s, t) the value n * count[c], where count[c] is the number of appearances of c in s.
	Then, ρ(s, t) = n * sum(count[c]), for every c in t. In order, to maximize this, you will have to choose c for which count[c] is maximum.
	Let num be the number of c's for which count[c] is maximum. The answer will be num ^ n, because, for every position in t, you have num characters to choose from.
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
#define cp(a,b)	( (conj(a)*(b)).imag() )
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

int n;
string s;
char c[] = { 'A','C','G','T' };
int cnt[5];

int main() {
	io;
	cin >> n >> s;
	int mx = -1;
	loop(i, 0, n - 1) {
		loop(j, 0, 3) {
			if (s[i] == c[j]) cnt[j]++;
			mx = max(cnt[j], mx);
		}
	}
	ll p = 0;
	loop(i, 0, 3)
		if (cnt[i] == mx) p++;
	ll ans = 1;
	loop(i, 1, n)
		ans = (ans * p) % mod;
	cout << ans;
}