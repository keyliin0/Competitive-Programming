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

vector<int> t;
int n, k;
int F[N];
int S[N];

int main() {
	scanf("%d%d", &n, &k);
	t.resize(n);
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		S[i] = t[i];
	}
	loop(i, 0, k - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		if (t[a] > t[b]) F[a]++;
		if (t[b] > t[a]) F[b]++;
	}
	sort(t.begin(), t.end());
	loop(i, 0, n - 1) {
		auto it = lower_bound(t.begin(), t.end(), S[i]);
		int ans = it - t.begin();
		printf("%d ",ans - F[i]);
	}
}