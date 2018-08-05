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

int n, m;
int t[5001], t2[5001],freq[101];

bool comapre(int &i,int &j) {
	if (freq[i] == freq[j])
		return i > j;
	return freq[i] > freq[j];
}

int main() {
	scanf("%d%d",&n,&m);
	int mx = 0;
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		t2[i] = t[i];
		freq[t[i]]++;
		mx = max(freq[t[i]], mx);
	}
	sort(t, t + n, comapre);
	sort(t2, t2 + n,comapre);
	int r = mx, ans = 0;
	loop(i, 0, n - 1) {
		if (r == n) r = 0;
		if (t[i] != t2[r]) ans++;
		r++;
	}
	printf("%d\n",ans);
	loop(i, 0, n - 1) {
		if (r == n) r = 0;
		printf("%d %d\n",t[i],t2[r]);
		r++;
	}
}