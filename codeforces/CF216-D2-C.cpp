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

vector<int> v;
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	loop(i, 1, k)
		v.push_back(1);
	int last = n;
	while (last <= m + n) {
		v.push_back(last);
		last++;
		if (last <= m + n) {
			loop(i, 1, k - 1)
				v.push_back(last );
			last = last + n - 1 - (k == 1);
		}
	}
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ",v[i]);
}