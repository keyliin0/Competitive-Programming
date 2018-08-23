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

int n, m;
int a[N], b[N], cnt[32];
int main() {
	scanf("%d%d", &n, &m);
	loop(i, 0, n - 1){
		scanf("%d",&a[i]);
		loop(j, 0, 30)
			if (a[i] & (1 << j)) cnt[j]++;
	}
	loop(i, 0, m - 1) {
		scanf("%d", &b[i]);
	}
	sort(b, b + m);
	int ans = 0;
	loop(i, 0, m - 1) {
		if (cnt[b[i]]) {
			cnt[b[i]]--;
			ans++;
		}
		else {
			loop(j, b[i] + 1, 30) {
				if (cnt[j]) {
					cnt[j]--;
					ans++;
					loop(k, b[i], j - 1) 
						cnt[k]++;
					break;
				}
			}
		}
	}
	printf("%d",ans);
}