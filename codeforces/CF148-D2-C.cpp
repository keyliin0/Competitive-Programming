/* 
	in general we can solve this problem with a greedy approach
	we make b elements before the a elements
	we can do that by fixing the first element and the b next elements will have greater sum then all previous integers
	then we print a integers which will be equal to the last integer + 1
	we can fill the rest with 1
	for case b = 0 and a = n - 1 there is no answer because if we fix the first element the next element
	will be greater than the sum of the previous elements
	so we must treat this case carefully
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

int n, a, b;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	if (n == 1) {
		printf("1");
		return 0;
	}
	if (b == 0) {
		if (a == n - 1) {
			printf("-1");
			return 0;
		}
		printf("5 4");
		n -= a;
		int cnt = 6;
		while (a--) printf(" %d",cnt++);
		loop(i, 1, n - 2)
			printf(" 1");
		return 0;
	}
	int sum = 1;
	n -= b + a;
	printf("1");
	while (b--) {
		sum *= 2;
		printf(" %d", sum);
	}
	while (a--) printf(" %d",++sum);
	loop(i, 1, n - 1)
		printf(" 1");
}
