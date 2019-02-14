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
const double EPS = 1e-18;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

bool prime[2 * N];
int t[N];
int n;

void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
}

int main() {
	generateprime(2 * 1e6);
	scanf("%d", &n);
	int cnt1 = 0;
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		cnt1 += t[i] == 1;
	}
	vector<int> ans;
	if (cnt1) {
		for (int i = 0; i < cnt1; i++)
			ans.push_back(1);
		loop(i, 0, n - 1) {
			if (t[i] != 1 && prime[t[i] + 1]) {
				ans.push_back(t[i]);
				break;
			}
		}
	}
	loop(i, 0, n - 1) {
		loop(j, i + 1, n - 1) {
			if (prime[t[i] + t[j]]) {
				if (ans.size() < 2) {
					ans.clear();
					ans.push_back(t[j]);
					ans.push_back(t[i]);
				}
			}
		}
	}
	if (ans.size() < 1) {
		ans.push_back(t[0]);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}