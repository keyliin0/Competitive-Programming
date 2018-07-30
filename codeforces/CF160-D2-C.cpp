/*
	first we sort all numbers
	we know that if freq[t[i]] * n >= k then the first number should be t[i]
	for the second element we know that each element can be selected freq[t[i]] , time t[i] is the first element of the pair
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

int t[N];
map<int, int> freq;
int n;
ll k;

int main() {
	scanf("%d%lld",&n,&k);
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		freq[t[i]]++;
	}
	sort(t, t + n);
	int ans1, ans2;
	loop(i, 0, n - 1) {
		if (i > 0 && t[i] == t[i - 1]) continue;
		if (k <= (ll)freq[t[i]] * n) {
			ans1 = t[i];
			break;
		}
		else k -= (ll)freq[t[i]] * n;
	}
	loop(i, 0, n - 1) {
		if (k <= freq[ans1]) {
			ans2 = t[i];
			break;
		}
		else k -= freq[ans1];
	}
	printf("%d %d",ans1,ans2);
}