/*
	iterate through all divisors and check if this divisor appeared in an index greater or equal to i - y
	edit : after thinking about it only store the index of the last appearance each time
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
vector<int> t[100005];

bool valid(int x,int idx) {
	auto it = lower_bound(t[x].begin(), t[x].end(), idx);
	return it == t[x].end();
}

int main() {
	scanf("%d",&n);
	loop(j,1,n) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = 0;
		if (y == 0) {
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					ans++;
					t[i].push_back(j);
					if (x / i != i) {
						ans++;
						t[x / i].push_back(j);
					}
				}
			}
			ans += 2;
			t[x].push_back(j);
		}
		else if(x != 1){
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					ans += valid(i, j - y);
					t[i].push_back(j);
					if (x / i != i) {
						ans += valid(x / i, j - y);
						t[x / i].push_back(j);
					}
				}
			}
			ans += valid(x, j - y);
			t[x].push_back(j);
		}
		printf("%d\n",ans);
	}
}