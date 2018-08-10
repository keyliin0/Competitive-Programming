/*
	there is only 2 possible string rbrbrb.. or brbrbrbr..
	for each one we find how many swaps we can make first which is max(r,b) - min(r,b) then we must paint the rest 
	so we end up with max(b, r) - min(b, r) + max(b, r) - (max(b, r) - min(b, r))
	which is max(b,r) in the end 
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

string s;
char c[] = { 'r','b' };
int n;

int main() {
	cin >> n >> s;
	int idx1 = 0, idx2 = 1, b1 = 0, b2 = 0, r1 = 0, r2 = 0;
	loop(i, 0, n - 1) {
		if (c[idx1 % 2] != s[i]) {
			if (s[i] == 'b') b1++;
			else r1++;
		}
		if (c[idx2 % 2] != s[i]) {
			if (s[i] == 'b') b2++;
			else r2++;
		}
		idx1++;
		idx2++;
	}
	int ans1 = max(b1, r1);
	int ans2 = max(b2, r2);
	cout << min(ans1, ans2);
}