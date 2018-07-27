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

string s;
int n, p;
int dp[1005][30][30][2];

int solve(int i,int a,int b,int change) {
	if (i == n) return change;
	int &ret = dp[i][a][b][change];
	if (ret != -1) return ret;
	for (int j = (change ? 0 : (s[i] - 'a')); j < p; j++)
		if (j != a && j != b)
			ret = max(ret, solve(i + 1, b, j, change || (s[i] - 'a') != j));
	return ret;
}

void build(int i,int a,int b,int change) {
	if (i == n) return;
	for (int j = (change ? 0 : (s[i] - 'a')); j < p; j++)
		if (j != a && j != b && solve(i, a, b, change) == solve(i + 1, b, j, change || (s[i] - 'a') != j)) {
			char c = j + 'a';
			cout << c;
			build(i + 1, b, j, change || (s[i] - 'a') != j);
			return;
		}
}


int main() {
	cin >> n >> p >> s;
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 28, 28, 0);
	if (ans) build(0, 28, 28, 0);
	else cout << "NO";
}