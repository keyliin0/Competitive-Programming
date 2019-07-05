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
 
pair<int, int> seg[N];
int n;
int t[N];
int q;
 
void build(int p, int s, int e) {
	if (s == e) {
		seg[p].first = t[s];
		return;
	}
	build(2 * p, s, (s + e) / 2);
	build(2 * p + 1, (s + e) / 2 + 1, e);
	seg[p].first = seg[2 * p].first + seg[2 * p + 1].first;
	if (seg[p].first >= 10) seg[p].second++;
	seg[p].first %= 10;
	seg[p].second += seg[2 * p].second + seg[2 * p + 1].second;
}
 
pair<int,int> get(int p, int s, int e, int a, int b) {
	if (s >= a && e <= b)
		return { seg[p].first,seg[p].second };
	if (s > b || e < a)
		return { 0,0 };
	pair<int, int> p1 = get(2 * p, s, (s + e) / 2, a, b);
	pair<int, int> p2 = get(2 * p + 1, (s + e) / 2 + 1, e, a, b);
	pair<int, int> res = { 0,0 }; 
	res.first = p1.first + p2.first;
	if (res.first >= 10) res.second++;
	res.first %= 10;
	res.second += p1.second + p2.second;
	return res;
}
 
 
int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	build(1, 0, n - 1);
	scanf("%d",&q);
	while (q--) {
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n",get(1,0,n-1,l-1,r-1).second);
	}
}