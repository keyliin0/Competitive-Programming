/*
	there are two ways for optimal sol :
		- make the operation on a prefix of length i then do the operation on the suffix by going back
		- do the operation to a suffix of length i then do the rest on a the rest prefix left
*/
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

string s;
int pre[1005], suf[1005];

int getmin(char x) {
	return min(x - 'A', ('Z' - x) + 1);
}

int main() {
	io;
	int test;
	cin >> test;
	while (test--) {
		cin >> s;
		if (s.size() == 1) {
			cout << getmin(s[0]) << "\n";
			continue;
		}
		int cnt = 0;
		memset(pre, 0, sizeof pre);
		memset(suf, 0, sizeof suf);
		pre[0] = getmin(s[0]);
		for (int i = 1; i < s.size(); i++) {
			pre[i] += pre[i - 1];
			if (s[i] == 'A') cnt++;
			else {
				pre[i] += getmin(s[i]) + 1;
				if (cnt) {
					pre[i] += cnt;
					cnt = 0;
				}
			}
		}
		cnt = 0;
		suf[s.size() - 1] = getmin(s.back());
		for (int i = s.size() - 2; i >= 0; i--) {
			suf[i] += suf[i + 1];
			if (s[i] == 'A') cnt++;
			else {
				suf[i] += getmin(s[i]) + 1;
				if (cnt) {
					suf[i] += cnt;
					cnt = 0;
				}
			}
		}
		int ans1 = pre[s.size() - 1], ans2 = suf[0] + 1;
		int curr = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (suf[i + 1]) {
				ans1 = min(ans1, pre[i] + i + 1 + suf[i + 1]);
			}
			else ans1 = min(ans1, pre[i]);
		}
		for (int i = s.size() - 1; i >= 1; i--) {
			if (pre[i - 1]) {
				ans2 = min(ans2, 1 + suf[i] + (int)(s.size() - i) + pre[i - 1]);
			}
			else ans2 = min(ans2, suf[i] + 1);
		}
		cout << min(ans1, ans2) << "\n";
	}
}