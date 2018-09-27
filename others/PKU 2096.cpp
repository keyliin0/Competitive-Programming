//#include <bits/stdc++.h>
#include <iostream>

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
//typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

double n, s;
double dp[1005][1005];
bool vis[1005][1005];

double solve(int i, int j) {
	if ((i < 0 || j < 0) || (i == 0 && j == 0)) return 0; 
	double &ret = dp[i][j];
	if (vis[i][j]) return ret;
	vis[i][j] = 1;
	ret = ((i / n * (s - j) / s) * solve(i - 1, j) + ((j / s) * (n - i) / n) * solve(i, j - 1) + (i / n * j / s) * solve(i - 1, j - 1) + 1) / (1 - (s - j) / s * (n - i) / n);
	return ret;
}

int main() {
	cin >> n >> s;
	double ans = solve(n - 1, s - 1) + 1;
	cout << fixed << setprecision(4) << ans;
}