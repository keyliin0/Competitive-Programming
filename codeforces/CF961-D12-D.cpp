/*
	check if a solution exist if the 1st and 2nd point are collinear , then 1st point and 3rd point 
	if both cases fail then if a solution exist the 2nd and the 3rd point must be collinear
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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

struct Point{
	int x, y;
};

int n;
Point t[N];
bool vis[N];

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

bool check(int p1,int p2) {
	int a = t[p1].x - t[p2].x, b = t[p1].y - t[p2].y;
	int g = GCD(a, b);
	a /= g;
	b /= g;
	memset(vis, 0, sizeof vis);
	vis[p1] = 1;
	vis[p2] = 1;
	int p3 = -1,p4 = -1;
	loop(i, 0, n - 1) {
		if (vis[i]) continue;
		int c = t[p1].x - t[i].x, d = t[p1].y - t[i].y;
		g = GCD(c, d);
		c /= g;
		d /= g;
		if (a != c || b != d) {
			if(p3 == -1) p3 = i;
			else if (p4 == -1) p4 = i;
		}
		else vis[i] = 1;
	}
	if (p3 == -1 || p4 == -1) return 1;
	a = t[p3].x - t[p4].x, b = t[p3].y - t[p4].y;
	g = GCD(a, b);
	a /= g;
	b /= g;
	vis[p3] = 1;
	vis[p4] = 1;
	loop(i, 0, n - 1) {
		if (vis[i]) continue;
		int c = t[p3].x - t[i].x, d = t[p3].y - t[i].y;
		g = GCD(c, d);
		c /= g;
		d /= g;
		if (a != c || b != d) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	if (n <= 3) {
		printf("YES");
		return 0;
	}
	loop(i, 0, n - 1) {
		scanf("%d%d", &t[i].x, &t[i].y);
	}
	if (check(0, 1) || check(0, 2) || check(1, 2)) printf("YES");
	else printf("NO");
}