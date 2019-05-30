#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int k;
int in[555];
bool v[555][555];

int main() {
	scanf("%d",&k);
	if (k % 2 == 0) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	vector<pair<int,int> > ans;
	int n = 2;
	ans.push_back({ 1,2 });
	in[1]++, in[2]++;
	if (k == 1) {
		printf("%d %d\n", n, ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
		return 0;
	}
	loop(i, 1, k - 1) {
		ans.push_back({ 1,++n });
		in[1]++;
		in[n]++;
	}
	in[n]++, in[n + 1];
	v[n][n + 1] = 1;
	ans.push_back({ n,n + 1 });
	n++;
	v[n][n + 1] = 1;
	in[n]++, in[n + 1];
	ans.push_back({ n,n + 1 });
	n++;
	loop(i, 3, n) {
		loop2(j, n, i) {
			if (in[j] == k || in[i] == k || i == j || v[i][j]) continue;
			in[j]++;
			in[i]++;
			ans.push_back({ i,j });
			v[i][j] = 1;
			v[j][i] = 1;
		}
	}
	int s = n + 1;
	loop(i, 1, k - 1) {
		ans.push_back({ 2,++n });
		in[2]++;
		in[n]++;
	}
	in[n]++, in[n + 1];
	v[n][n + 1] = 1;
	ans.push_back({ n,n + 1 });
	n++;
	in[n]++, in[n + 1];
	v[n][n + 1] = 1;
	ans.push_back({ n,n + 1 });
	n++;
	loop(i, s, n) {
		loop2(j, n, i) {
			if (in[j] == k || in[i] == k || i == j || v[i][j]) continue;
			in[j]++;
			in[i]++;
			ans.push_back({ i,j });
			v[i][j] = 1;
			v[j][i] = 1;
		}
	}
	printf("%d %d\n", n, ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	/*for (int i = 1; i <= n; i++) {
		printf("%d %d --\n", i, in[i]);
	}*/
}