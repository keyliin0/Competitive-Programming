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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
point t[1005];

int main() {
	cin >> n;
	loop(i, 0, n) {
		int x, y;
		cin >> x >> y;
		t[i] = point(x, y);
	}
	int ans = 0;
	loop(i, 1, n - 1) {
		point a = t[i - 1], b = t[i], c = t[i + 1];
		if (a.Y == b.Y) {
			if (a.X < b.X && c.Y > b.Y) ans++; // right up
			if (a.X > b.X && c.Y < b.Y) ans++; // left down
		}
		else if(a.X == b.X){
			if (a.Y < b.Y && c.X < b.X) ans++; // up left
			if (a.Y > b.Y && c.X > b.X) ans++; //down right
		}
	}
	cout << ans;
}