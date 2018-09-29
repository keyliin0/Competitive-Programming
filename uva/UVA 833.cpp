/*
	sort all segments by their max Y (decreasing order)
	go through all the segments if the current x is between the current segment then change the value of x 
	if left Y > right Y then x = right x 
	otherwise if right Y > left Y then x = left x
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

int n, m;

struct seg{
	int x1, x2, y1, y2;
};

seg t[200];

bool compare(seg i, seg j) {
	return max(i.y2, i.y1) > max(j.y1, j.y2);
}

int main() {
	int test;
	scanf("%d",&test);
	bool line = 0;
	while (test--) {
		if (line) printf("\n");
		line = 1;
		scanf("%d", &n);
		loop(i, 0, n - 1) {
			scanf("%d%d%d%d", &t[i].x1, &t[i].y1, &t[i].x2, &t[i].y2);
			if (t[i].x1 > t[i].x2) {
				swap(t[i].x1, t[i].x2);
				swap(t[i].y1, t[i].y2);
			}
		}
		sort(t, t + n, compare);
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			int start = -1;
			loop(i, 0, n - 1) {
				if (x >= t[i].x1 && x <= t[i].x2 && (t[i].y1 < y || t[i].y2 < y)) {
					if (t[i].y1 > t[i].y2) x = t[i].x2;
					else if(t[i].y1 < t[i].y2) x = t[i].x1;
				}
			}
			printf("%d\n",x);
		}
	}
}