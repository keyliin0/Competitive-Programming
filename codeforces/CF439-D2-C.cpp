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

queue<int> even, odd;
int n, k, p;

int main() {
	scanf("%d%d%d", &n, &k, &p);
	loop(i, 0, n - 1) {
		int a;
		scanf("%d",&a);
		if (a & 1) odd.push(a);
		else even.push(a);
	}
	vector<vector<int> > ans1;
	while (ans1.size() < p && !even.empty()) {
		int u = even.front();
		even.pop();
		ans1.push_back(vector<int>(1, u));
	}
	while (ans1.size() < p) {
		if (odd.size() < 2) {
			printf("NO");
			return 0;
		}
		int u = odd.front();
		odd.pop();
		ans1.push_back(vector<int>(1, u));
		u = odd.front();
		odd.pop();
		ans1[ans1.size() - 1].push_back(u);
	}
	vector<vector<int> > ans2;
	while (ans2.size() < k - p) {
		if (odd.empty()) {
			printf("NO");
			return 0;
		}
		int u = odd.front();
		odd.pop();
		ans2.push_back(vector<int>(1, u));
	}
	if (odd.size() % 2 != 0) {
		printf("NO");
		return 0;
	}
	if (ans1.size()) {
		while (!odd.empty()) {
			int u = odd.front();
			odd.pop();
			ans1[ans1.size() - 1].push_back(u);
		}
		while (!even.empty()) {
			int u = even.front();
			even.pop();
			ans1[ans1.size() - 1].push_back(u);
		}
	}
	else {
		while (!odd.empty()) {
			int u = odd.front();
			odd.pop();
			ans2[ans2.size() - 1].push_back(u);
		}
		while (!even.empty()) {
			int u = even.front();
			even.pop();
			ans2[ans2.size() - 1].push_back(u);
		}
	}
	printf("YES\n");
	for (int i = 0; i < ans1.size(); i++) {
		printf("%d ", ans1[i].size());
		for (int j = 0; j < ans1[i].size(); j++)
			printf("%d ", ans1[i][j]);
		printf("\n");
	}
	for (int i = 0; i < ans2.size(); i++) {
		printf("%d ", ans2[i].size());
		for (int j = 0; j < ans2[i].size(); j++)
			printf("%d ", ans2[i][j]);
		printf("\n");
	}
}