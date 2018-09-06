/*
	if sum from left to right <= m * t we must check if max from L to R <= t 
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
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll arr[N];
int n;
ll a, b;

int main() {
	scanf("%lld%lld%d", &a, &b, &n);
	loop(i, 1, 1e6) {
		arr[i] = a + (i - 1) * b;
		arr[i] += arr[i - 1];
	}
	while (n--) {
		ll l, t, m;
		scanf("%lld%lld%lld",&l,&t,&m);
		int ans = -1, left = l , right = N;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] - arr[l - 1] <= m * t && a + (mid - 1) * b <= t) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		printf("%d\n",ans);
	}
}