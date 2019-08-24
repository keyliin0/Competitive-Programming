/*
		answer = total number of permutations - total number of bad permutations
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
 
int n;
pair<int, int> t[N];
 
ll MOD = 998244353;
ll f[N];
ll freqa[N], freqb[N];
 
bool cmp(pair<int, int> &i, pair<int, int> &j) {
	if (i.first == j.first) return i.second < j.second;
	return i.first < j.first;
}
 
 
int main() {
	scanf("%d", &n);
	f[0] = 1;
	loop(i, 1, n) {
		f[i] = f[i - 1] * i;
		f[i] %= MOD;
	}
	loop(i, 0, n - 1) {
		scanf("%d%d", &t[i].first, &t[i].second);
		freqa[t[i].first]++;
		freqb[t[i].second]++;
	}
	sort(t, t + n, cmp);
	ll a = 1, cnt = 1;
	loop(i, 0, n - 1) {
		//cout << t[i].first << " " << t[i].second << "\n";
		if (i + 1 < n && (t[i].first > t[i + 1].first || t[i].second > t[i + 1].second))
			a = 0;
		if (i && t[i].first == t[i - 1].first && t[i].second == t[i - 1].second) cnt++;
		else {
			a *= f[cnt];
			a %= MOD;
			cnt = 1;
		}
	}
	a *= f[cnt];
	ll b = 1, c = 1;
	loop(i, 1, n) {
		b *= f[freqa[i]];
		b %= MOD;
		c *= f[freqb[i]];
		c %= MOD;
	}
	ll d = ((((b + c) % MOD) - a + MOD) % MOD + MOD) % MOD;
	cout << (((f[n] - d) % MOD) + MOD) % MOD;
}