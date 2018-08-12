/*
	suppose that will always use the ith point then calculate the slope with the other points 
	the answer will be the max freqnuency of a slope
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

struct Point{
	int x, y;
};

Point t[705];
map<pair<int, int>,int > slope;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main() {
	int tests;
	cin >> tests;
	string line;
	getline(cin, line);
	getline(cin, line);
	while (tests--) {
		n = 0;
		while (getline(cin, line)) {
			if (line == "") break;
			sscanf(line.c_str(), "%d %d", &t[n].x, &t[n].y);
			n++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			slope.clear();
			for (int j = i + 1; j < n; j++) {
				int currx = t[i].x - t[j].x;
				int curry = t[i].y - t[j].y;
				int g = GCD(currx, curry);
				currx /= g;
				curry /= g;
				slope[{currx, curry}]++;
				ans = max(ans, slope[{currx, curry}] + 1);
			}
		}
		printf("%d\n",ans);
		if (tests) printf("\n");
	}
}
