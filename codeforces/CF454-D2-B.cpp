/*
	first check the index where the array is no longer sorted in increasing order
	and check if we can get a sorted array if we take the sub array from this index to n to the beginning of the array
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

int n;
int t[N];

int main() {
	scanf("%d",&n);
	int idx = -1;
	loop(i, 0, n - 1) {
		scanf("%d",&t[i]);
		if (i > 0 && t[i] < t[i - 1] && idx == -1) idx = i;
	}
	if (idx == -1) idx = 0;
	int i = idx;
	while (i < n) {
		if (i != n - 1 && t[i] > t[i + 1]) {
			printf("-1");
			return 0;
		}
		else if (i == n - 1 && t[i] > t[0] && idx!= 0) {
			printf("-1");
			return 0;
		}
		i++;
	}
	printf("%d",(n - idx) % n);
}