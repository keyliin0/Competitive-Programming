/*
	sum of rectangle (x1,x2,y1,y2) = sum(x1,x2) * sum(y1,y2)
	sum(x1,x2) = Sx1 + S(x1 + 1) + ... + Sx2 
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

ll sum[4005], freq[N];
ll a;
string s;

int main() {
	cin >> a >> s;
	s = '/' + s;
	loop(i, 1, s.size() - 1)
		sum[i] = sum[i - 1] + (s[i] - '0');
	loop(i, 1, s.size() - 1) {
		loop(j, i, s.size() - 1) {
			freq[sum[j] - sum[i - 1]]++;
		}
	}
	if (a == 0) {
		cout << freq[0] * ((s.size() - 1) * (s.size() - 1) + s.size()- 1 - freq[0]);
		return 0;
	}
	ll ans = 0;
	loop(i, 1, 1e5)
		if (a % i == 0 && (a / i < 1e5)) ans += freq[i] * freq[a / i];
	cout << ans;
}