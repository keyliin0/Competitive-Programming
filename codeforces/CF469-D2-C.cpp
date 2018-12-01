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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
multiset<int> s;

int main() {
	scanf("%d",&n);
	if (n <= 3) {
		printf("NO");
		return 0;
	}
	if (n == 4) {
		printf("YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24");
		return 0;
	}
	if (n == 5) {
		printf("YES\n5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i != 4 && i != 6) s.insert(i);
	}
	printf("YES\n6 * 4 = 24\n");
	while (s.size() > 1) {
		int x1 = *(--s.end());
		auto it = --s.end();
		s.erase(it);
		int x2 = *(--s.end());
		it = --s.end();
		s.erase(it);
		s.insert(x1 - x2);
		printf("%d - %d = %d\n", x1, x2, x1 - x2);
	}
	int x = *s.begin();
	if(x == 1) printf("24 * 1 = 24");
	else printf("24 + 0 = 24");
}