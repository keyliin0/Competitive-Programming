/* 
	if we have a circle we can check the distance between the point and the center and compare it to the radius
	for a rectangle we need to compare the coordinates of the top left and bottom right to the point we want to check
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

struct fig{
	char c;
	double x1, x2, y1, y2;
	double x, y, r;
};

int n;
fig t[N];

bool check(double x1, double y1, double x2, double y2, double x3, double y3){
	return x3 > x1 && x3 < x2 && y3 < y1 && y3 > y2;
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)* (y1 - y2));
}

int main() {
	char c;
	while (cin >> c) {
		if (c == '*') break;
		if (c == 'c') {
			cin >> t[n].x >> t[n].y >> t[n].r;
		}
		else cin >> t[n].x1 >> t[n].y1 >> t[n].x2 >> t[n].y2;
		t[n].c = c;
		n++;
	}
	int test = 0;
	double x, y;
	while (cin >> x >> y) {
		if(x == 9999.9 && y == 9999.9) break;
		test++;
		bool flag = 1;
		for (int i = 0; i < n; i++) {
			if (t[i].c == 'c') {
				if (distance(t[i].x, t[i].y, x, y) <= t[i].r) {
					flag = 0;
					cout << "Point " << test << " is contained in figure " << i + 1 << endl;
				}
			}
			else {
				if (check(t[i].x1, t[i].y1, t[i].x2, t[i].y2, x, y)) {
					flag = 0;
					cout << "Point " << test << " is contained in figure " << i + 1 << endl;
				}
			}
		}
		if(flag) cout << "Point " << test << " is not contained in any figure" << endl;
	}
}
