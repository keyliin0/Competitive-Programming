/*
	get lis in nlogn for each index starting from 1 and n
	then find the ans
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
int t[N];
int cnt1[N], cnt2[N];

int main() {
	while (scanf("%d", &n) != EOF) {
		loop(i, 0, n - 1)
			scanf("%d",&t[i]);
		vector<int> v;
		v.push_back(t[0]);
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		cnt1[0] = 1;
		loop(i, 1, n - 1) {
			if (t[i] > v[v.size() - 1]) {
				cnt1[i] = v.size() + 1;
				v.push_back(t[i]);
			}
			else {
				int idx = lower_bound(v.begin(), v.end(), t[i]) - v.begin();
				cnt1[i] = idx + 1;
				v[idx] = t[i];
			}
		}
		v.clear();
		v.push_back(t[n - 1]);
		loop2(i, n - 2, 0) {
			if (t[i] > v[v.size() - 1]) {
				cnt2[i] = v.size() + 1;
				v.push_back(t[i]);
			}
			else {
				int idx = lower_bound(v.begin(), v.end(), t[i]) - v.begin();
				cnt2[i] = idx + 1;
				v[idx] = t[i];
			}
		}
		int ans = 1;
		loop(i, 0, n - 1) {
			int x = min(cnt1[i] - 1, cnt2[i] - 1);
			ans = max(ans, x * 2 + 1);
		}
		printf("%d\n",ans);
	}
}