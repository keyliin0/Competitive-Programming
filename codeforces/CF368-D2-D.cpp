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
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, p;
int t[N];
map<int, int> freq;
map<pair<int, int>, int> freq2;
int M[N];

int main() {
	scanf("%d%d%d", &n, &m, &p);
	loop(i, 1, n)
		scanf("%d",&t[i]);
	int total = 0;
	loop(i, 0, m - 1) {
		int a;
		scanf("%d",&a);
		freq[a]++;
		if (freq[a] == 1) total++;
	}
	vector<int> ans;
	for (ll i = 1; i <= n && i <= (ll)1LL + 1LL * (m - 1) * p; i++) {
		int &x = freq2[{i % p, t[i]}];
		x++;
		if (x == freq[t[i]]) M[i % p]++;
		if (M[i % p] == total) ans.push_back(1);
	}
	ll l = 1, r = (ll)1LL + 1LL * (m - 1) * p;
	while (r < n) {
		int &x1 = freq2[{l % p, t[l]}];
		if (x1 == freq[t[l]]) M[l % p]--;
		x1--;
		l++;
		r++;
		int &x2 = freq2[{r % p, t[r]}];
		x2++;
		if (x2 == freq[t[r]]) M[r % p]++;
		if (M[l % p] == total) ans.push_back(l);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
}