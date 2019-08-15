#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
string s, t;
int len[N];
 
int main() {
	cin >> s >> t;
	int idx = t.size() - 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		len[i] = len[i + 1];
		if (idx >= 0 && t[idx] == s[i]) len[i]++, idx--;
	}
	int ans = 0;
	idx = 0;
	int curr_len = 0;
	for (int i = 0; i < s.size(); i++) {
		int l = 0, r = s.size() - i;
		while (l <= r) {
			int m = (l + r) / 2;
			if (curr_len + len[i + m] >= t.size()) {
				ans = max(ans, m);
				l = m + 1;
			}
			else r = m - 1;
		}
		if (idx != t.size() && t[idx] == s[i]) idx++, curr_len++;
	}
	cout << ans;
}