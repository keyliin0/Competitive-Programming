/*
	we know that each one can take up to (w * n) / m
	let's call this number x
	notice that using what is left of the bottles when trying to give each one x is the best strategy and give the optimal answer (if it exist) 
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
double w;
double t[105];
int cnt[105];
vector<pair<int, double> > ans[100];

int main() {
	scanf("%d%lf%d", &n, &w, &m);
	for (int i = 0; i < n; i++)
		t[i] = w;
	double x = (double)(n * w) / m;
	for (int j = 0; j < m; j++) {
		double need = x;
		bool done = 0;
		for (int i = 0; i < n && !done; i++) {
			if (cnt[i] == 2 || t[i] <= EPS) continue;
			if (t[i] >= need) {
				ans[j].push_back({ i + 1,need });
				t[i] -= need;
				need = 0;
				cnt[i]++;
				done = 1;
			}
			else {
				ans[j].push_back({ i + 1,t[i] });
				need -= t[i];
				t[i] = 0;
				cnt[i]++;
			}
			if (need <= EPS) {
				done = 1;
				break;
			}
		}
		if (!done) {
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d %lf ", ans[i][j].first, ans[i][j].second);
		}
		printf("\n");
	}
}