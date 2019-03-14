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

int a[505][505], b[505][505];
int n, m;
vector<int> aa[1005], bb[1005];

int main() {
	scanf("%d%d",&n,&m);
	loop(i, 1, n)
		loop(j, 1, m) {
			scanf("%d", &a[i][j]);
			aa[i + j].push_back(a[i][j]);
	}
	loop(i, 1, n)
		loop(j, 1, m) {
			scanf("%d", &b[i][j]);
			bb[i + j].push_back(b[i][j]);
		}
	loop(i, 1, n + m) {
		sort(aa[i].begin(), aa[i].end());
		sort(bb[i].begin(), bb[i].end());
		for(int j = 0;j < aa[i].size();j++)
			if (aa[i][j] != bb[i][j]) {
				printf("NO");
				return 0;
			}
	}
	printf("YES");
}