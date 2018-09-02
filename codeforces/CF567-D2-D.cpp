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

int n, k, a, q;
set<int> s;

int main() {
	scanf("%d%d%d%d", &n, &k, &a, &q);
	s.insert(0);
	s.insert(n + 1);
	int p = (n + 1) / (a + 1);
	loop(i,1,q) {
		int x;
		scanf("%d",&x);
		if (s.find(x) != s.end()) continue;
		auto it1 = s.lower_bound(x);
		it1--;
		auto it2 = s.lower_bound(x + 1);
		p -= (*it2 - *it1) / (a + 1);
		p += (*it2 - x) / (a + 1);
		p += (x - *it1) / (a + 1);
		if (p < k) {
			printf("%d",i);
			return 0;
		}
		s.insert(x);
	}
	printf("-1");
}