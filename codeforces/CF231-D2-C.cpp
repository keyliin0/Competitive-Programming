/*
	if we take a sub array from the original array L the leftmost index and R the right index, 
	we know that all the elements in this subarray must be equal to T[R] so we need the sum of this array to be T[R] * ( R - L + 1)
	we can use that to check for the longest subarray such that  T[R] * ( R - L + 1) <= K after sorting the array
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

int n, k;
ll t[N],pre[N];

int main() {
	scanf("%d%d",&n,&k);
	loop(i, 1, n)
		scanf("%lld", &t[i]);
	sort(t + 1, t + n + 1);
	loop(i, 1, n)
		pre[i] = pre[i - 1] + t[i];
	int r = 1, ans = 0,mx = -1;
	for (int i = 1; i <= n; i++) {
		while (r <= n && (t[r] * (r - i + 1)) - (pre[r] - pre[i - 1]) <= k) {
			if (r - i + 1 > mx) {
				mx = r - i + 1;
				ans = t[r];
			}
			r++;
		}
	}
	printf("%d %d",mx,ans);
}