/*
	Number of cells which contain a segment of the circle 8n - 4
	we can check the distance between the radius for the inside ans
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

int	n;

int main() {
	bool line = 0;
	while (scanf("%d", &n) != EOF) {
		if (line) printf("\n");
		line = 1;
		int ans = 0;
		double r = n - 0.5;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				double d = (double)sqrt((double)i * i + j * j);
				if (d <= r) ans++;
			}
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, 8 * n - 4);
		printf("There are %d cells completely contained in the circle.\n", ans * 4);
	}

}
