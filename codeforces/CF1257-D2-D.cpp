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
const int mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
int a[N];
int suf[N];
pair<int, int> t[N];

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d", &n);
		vector<int> all;
		loop(i, 0, n - 1) {
			scanf("%d",&a[i]);
			all.push_back(a[i]);
		}
		scanf("%d", &m);
		loop(i, 0, m - 1) {
			scanf("%d%d", &t[i].first, &t[i].second);
			all.push_back(t[i].first);
		}
		sort(all.begin(), all.end());
		int cnt = 0;
		map<int, int> mp;
		mp[all[0]] = cnt++;
		loop(i, 1, all.size() - 1) {
			if (all[i] == all[i - 1]) continue;
			mp[all[i]] = cnt++;
		}
		loop(i, 0, cnt) suf[i] = 0;
		loop(i, 0, m - 1) suf[mp[t[i].first]] = max(suf[mp[t[i].first]], t[i].second);
		loop2(i, cnt - 1, 0) suf[i] = max(suf[i], suf[i + 1]);
		int ans = 0, l = 0, mx_so_far = 0;
		bool yes = 1;
		loop(i, 0, n - 1) {
			mx_so_far = max(mx_so_far, mp[a[i]]);
			if (suf[mx_so_far] < i - l + 1) {
				ans++;
				l = i;
				mx_so_far = mp[a[i]];
				if (!suf[mx_so_far]) yes = 0;
			}
		}
		if (yes) printf("%d\n",ans + 1);
		else printf("-1\n");
	}
}