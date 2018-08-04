/*
	each time check the numbers who have the ith bit 1 and check if the result is divsible by 2^i
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
int t[N];
vector<int> ans;

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		scanf("%d",&t[i]);
	}
	for (int j = 29; j >= 0; j--) {
		int p = 1 << j;
		int in = -1;
		loop(i, 0, n - 1) {
			if (t[i] & p) {
				if (in == -1) in = t[i];
				else in &= t[i];
				if (ans.size() && ans[ans.size() - 1] == t[i]) continue;
				ans.push_back(t[i]);
			}
		}
		if (in % p == 0) break;
		else ans.clear();
	}
	if (!ans.size()) printf("-1");
	else {
		printf("%d\n",ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d ",ans[i]);
	}
}