/*
	greedy approach : when trying to take 2 equal caracters try the next substring (which we'll pick the chars from) must be maximum size
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
 
int main() {
	io;
	cin >> s;
	string ans = "";
	deque<int> a, b, c;
	loop(i, 0, s.size() - 1) {
		if (s[i] == 'a') a.push_back(i);
		if (s[i] == 'b') b.push_back(i);
		if (s[i] == 'c') c.push_back(i);
	}
	int l = 0, r =  s.size() - 1;
	while (l <= r) {
		int aa = 0, bb = 0, cc = 0;
		while (!a.empty() && a.front() < l) a.pop_front();
		while (!b.empty() && b.front() < l) b.pop_front();
		while (!c.empty() && c.front() < l) c.pop_front();
		while (!a.empty() && a.back() > r) a.pop_back();
		while (!b.empty() && b.back() > r) b.pop_back();
		while (!c.empty() && c.back() > r) c.pop_back();
		if (a.size() >= 2) aa = a.back() - a.front();
		if (b.size() >= 2) bb = b.back() - b.front();
		if (c.size() >= 2) cc = c.back() - c.front();
		if (!aa && !bb && !cc) break;
		if (aa >= cc && aa >= bb) {
			l = a.front() + 1;
			r = a.back() - 1;
			a.pop_front();
			a.pop_back();
			ans += 'a';
		}
		else if (bb >= cc && bb >= aa) {
			l = b.front() + 1;
			r = b.back() - 1;
			b.pop_front();
			b.pop_back();
			ans += 'b';
		}
		else {
			l = c.front() + 1;
			r = c.back() - 1;
			c.pop_front();
			c.pop_back();
			ans += 'c';
		}
	}
	string ans2 = ans;
	reverse(ans.begin(), ans.end());
	if (a.size()) {
		ans = 'a' + ans;
	}
	else if (b.size()) ans = 'b' + ans;
	else if (c.size()) ans = 'c' + ans;
	cout << ans2 << ans;
}