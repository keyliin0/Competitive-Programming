/*
	we can take care of case n = 1 , n = 2 first
	then check if we have an arithmetic progression then we can add 2 numbers
	otherwise we have to check if we can make it an arithmetic progression by adding only 1 number
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
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	sort(t, t + n);
	if (n == 1) {
		printf("-1");
		return 0;
	}
	if (n == 2) {
		if (t[0] - t[1] == 0) {
			printf("1\n%d",t[0]);
			return 0;
		}
		if ((t[0] + t[1]) % 2 != 0) {
			printf("2\n%d %d",t[0] - (t[1]-t[0]),t[1]-t[0] + t[1]);
			return 0;
		}
		printf("3\n%d %d %d", t[0] - (t[1] - t[0]),(t[1] + t[0])/2 ,t[1] - t[0] + t[1]);
		return 0;
	}
	if (t[n - 1] == t[0]) {
		printf("1\n%d",t[0]);
		return 0;
	}
	int prog = t[1] - t[0],  p;
	bool c = 0,yes = 1;
	loop(i, 1, n - 1) {
		if (t[i] - t[i - 1] != prog) {
			p = (t[i] + t[i - 1]) / 2;
			if (c || t[i] - p != prog) {
				yes = 0;
				break;
			}
			c = 1;
		}
	}
	if (!yes) {
		prog = t[1] - ((t[1] + t[0]) / 2);
		loop(i, 2, n - 1) {
			if (t[i] - t[i - 1] != prog) {
				printf("0");
				return 0;
			}
		}
		printf("1\n%d", (t[1] + t[0]) / 2);
	}
	else if (c) printf("1\n%d",p);
	else printf("2\n%d %d", t[0] - (t[1] - t[0]), (t[1] - t[0]) + t[n - 1]);
}