/*
	greedy strategy : pass the exam as late as possible
	to check the last possible day of passing all exams use binary search
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
int d[N], a[N];
int at[N], last[N];

bool can(int mid) {
	memset(last, -1, sizeof last);
	memset(at, -1, sizeof at);
	loop(i, 0, mid - 1) {
		if (d[i] == 0) continue;
		last[d[i] - 1] = i;
	}
	loop(i, 0, m - 1) {
		if (last[i] == -1) return 0;
		at[last[i]] = i;
	}
	int rem = m, free = 0;
	loop(i, 0, mid - 1) {
		if (at[i] == -1) free++;
		else {
			if (free < a[at[i]]) return 0;
			free -= a[at[i]];
			rem--;
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	loop(i, 0, n - 1) {
		scanf("%d", &d[i]);
	}
	loop(i, 0, m - 1) {
		scanf("%d", &a[i]);
	}
	int l = m, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (can(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d", ans);
}