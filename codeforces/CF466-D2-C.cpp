/*
	if the sum of the array is not div by 3 then we cant split it
	otherwise we have to find the number of times the sum starting from the end become div by 3
	if we start from the beginning of the array and the current sum equal to the sum of the array / 3
	we cab use the suffix array to count the number of ways for the current index
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

ll t[N];
int sum[N];
int n;

int main() {
	scanf("%d",&n);
	ll tot = 0;
	loop(i, 0, n - 1) {
		scanf("%lld", &t[i]);
		tot += t[i];
	}
	if (tot % 3 != 0) {
		printf("0");
		return 0;
	}
	ll curr = 0;
	loop2(i, n - 1, 0) {
		curr += t[i];
		if (curr == tot / 3) sum[i]++;
		sum[i] += sum[i + 1];
	}
	ll ans = 0;
	curr = 0;
	loop(i, 0, n - 1) {
		curr += t[i];
		if (curr == tot / 3) ans += sum[i + 2];
	}
	printf("%lld",ans);
}