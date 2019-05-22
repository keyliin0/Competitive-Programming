/* 
	if a segment is removed then check if the left segment and right segment are equal merge them
	number the segments in asc order so its easier to check the number of the right and left segment using a set
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int p[N], t[N], sz[N];
int n;

int main() {
	scanf("%d",&n);
	loop(i, 1, n)
		p[i] = i,sz[i]++;
	loop(i, 1, n) {
		scanf("%d", &t[i]);
		if (t[i] == t[i - 1]) {
			p[i] = p[i - 1];
			sz[p[i]]++;
		}
	}
	set<int> cmps;
	set<pair<int, int> > s;
	loop(i, 1, n) {
		int x = p[i];
		cmps.insert(x);
		s.insert({ -sz[x],x });
	}
	int ans = 0;
	while (s.size()) {
		auto it = *(s.begin());
		if (cmps.find(it.second) == cmps.end()) {
			s.erase(it);
			continue;
		}
		ans++;
		cmps.erase(it.second);
		int num = it.second;
		int len = -it.first;
		s.erase(it);
		auto left = cmps.lower_bound(num);
		auto right = cmps.upper_bound(num);
		if (left == cmps.begin() || right == cmps.end()) continue;
		left--;
		int l = *left;
		int r = *right;
		if (t[l] == t[r]) {
			auto it2 = s.find({ -sz[l],l });
			auto it3 = s.find({ -sz[r],r });
			sz[l] += sz[r];
			s.erase(it2);
			s.erase(it3);
			s.insert({ -sz[l],l });
			cmps.erase(right);
		}
	}
	cout << ans;
}