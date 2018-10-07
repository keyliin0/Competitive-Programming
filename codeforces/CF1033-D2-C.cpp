/*
	1 - if we start iterating through the numbers in non-increasing order we guarantee that a[j] > a[j]
	2 - if alice already started from an index i and lost then we know if we can reach this index we win 
		because it will be bob's turn and if alice couldnt win starting from that index then bob can't win too
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

int n;
int t[N], dp[N];

int main() {
	scanf("%d", &n);
	vector<pair<int, int> > v;
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		v.push_back({ t[i], i });
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		dp[v[i].second] = 2;
		for (int j = v[i].first + v[i].second; j < n; j += v[i].first) {
			if (dp[j] == 2) {
				dp[v[i].second] = 1;
				break;
			}
		}
		for (int j = v[i].second - v[i].first; j >= 0; j -= v[i].first) {
			if (dp[j] == 2) {
				dp[v[i].second] = 1;
				break;
			}
		}
	}
	loop(i, 0, n - 1) {
		if (dp[i] == 1) printf("A");
		else printf("B");
	}
}