#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m;
int a[55][55], b[55][55];
int ar[55][55], br[55][55];

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			scanf("%d", &a[i][j]);
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			scanf("%d", &b[i][j]);
	loop(i, 0, n - 1) {
		vector<pair<int, int> > v;
		loop(j, 0, m - 1) {
			v.push_back({ a[i][j], j });
			v.push_back({ b[i][j], j });
		}
		sort(v.begin(), v.end());
		int c1 = 0, c2 = 0;
		loop(j, 0, v.size() - 1) {
			if (v[j].second == c1) {
				ar[i][c1] = v[j].first;
				c1++;
			}
			else if (v[j].second == c2) {
				br[i][c2] = v[j].first;
				c2++;
			}
			else {
				printf("Impossible");
				return 0;
			}
		}
	}
	loop(i, 0, n - 1) {
		loop(j, 0, m - 2) {
			if (ar[i][j] >= ar[i][j + 1] || br[i][j] >= br[i][j + 1]) {
				printf("Impossible");
				return 0;
			}
		}
	}
	loop(j, 0, m - 1) {
		loop(i, 0, n - 2) {
			if (ar[i][j] >= ar[i + 1][j] || br[i][j] >= br[i + 1][j]) {
				printf("Impossible");
				return 0;
			}
		}
	}
	printf("Possible");
}