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

pair<int, string> t[3005];
vector<int> h;
int ans[3005];
int n;

int main() {
	cin >> n;
	loop(i, 0, n - 1) {
		cin >> t[i].second >> t[i].first;
	}
	sort(t, t + n);
	loop(i, 0, n - 1) {
		if (t[i].first > i) {
			cout << "-1";
			return 0;
		}
		h.insert(h.begin() + i - t[i].first, i);
	}
	loop(i, 0, n - 1)
		ans[h[i]] = i + 1;
	loop(i, 0, n - 1)
		cout << t[i].second << " " << ans[i] << endl;
}