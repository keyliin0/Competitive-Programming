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
#define logg2  0.30102999566398119521373889472449L
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
int sum[N], t[N];

int main() {
	while (scanf("%d", &n) != EOF) {
		loop(i, 0, (1 << n) - 1) {
			scanf("%d",&t[i]);
		}
		memset(sum, 0, sizeof sum);
		loop(i, 0, (1 << n) - 1) {
			loop(j, 0, n - 1) {
				if ((i ^ (1 << j)) > (1 << n) - 1) continue;
				sum[i] += t[i ^ (1 << j)];
			}
		}
		int mx = 0;
		loop(i, 0, (1 << n) - 1) {
			loop(j, 0, n - 1) {
				if ((i ^ (1 << j)) > (1 << n) - 1) continue;
				mx = max(mx, sum[i] + sum[i ^ (1 << j)]);
			}
		}
		printf("%d\n",mx);
	}
}