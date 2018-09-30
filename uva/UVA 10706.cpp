/*
	the number of digit to represent k first consecutive numbers is length of digits k - 1 + log10(current number )  + 1
	calculating the accumulative sum for the recurrence gives us the total number of digits when writing the i-th number
	use binary search to determine what will be the i-th number and now just by iterating from 1 to i we find what is the n-th digit
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

int n;
ll t[N];

int main() {
	int test;
	scanf("%d",&test);
	loop(i, 1, 1e6) {
		t[i] = t[i - 1] + log10(i) + 1;
	}
	loop(i, 1, 1e6)
		t[i] += t[i - 1];
	while (test--) {
		scanf("%d", &n);
		int l = 1, r = 1e6, x;
		while (l <= r) {
			int m = (l + r) / 2;
			if (t[m] < n) l = m + 1;
			else {
				x = m;
				r = m - 1;
			}
		}
		int ans;
		n -= t[x - 1];
		for (int i = 1; i <= x; i++) {
			if ((int) log10(i) + 1 < n) n -= (int) log10(i) + 1;
			else {
				string s = to_string(i);
				ans = s[n - 1] - '0';
				break;
			}
		}
		printf("%d\n", ans);
	}
}