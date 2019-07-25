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
int oo = 1e5;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
int n;
int t[N][2];
 
pair<int,int> last(int start,int len) {
	int l = start, r = n;
	int idx = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (t[m][0] - t[start - 1][0] >= len || t[m][1] - t[start - 1][1] >= len) {
			idx = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	if (idx == -1) return { -1,-1 };
	else {
		if (t[idx][0] - t[start - 1][0] == len) return { idx,1 };
		else return { idx,2 };
	}
}
 
int main() {
	scanf("%d",&n);
	loop(i, 1, n) {
		int x;
		scanf("%d",&x);
		t[i][x - 1]++;
		t[i][0] += t[i - 1][0];
		t[i][1] += t[i - 1][1];
	}
	vector<pair<int, int> > ans;
	loop(i, 1, n) {
		int idx = 0;
		int a = 0, b = 0;
		bool yes = 1;
		while (idx != n) {
			pair<int, int> res = last(idx + 1, i);
			if (res.first == -1) {
				yes = 0;
				break;
			}
			idx = res.first;
			if (res.second == 1) a++;
			else b++;
		}
		if (a > b && t[n][0] - t[n - 1][0] != 1) yes = 0;
		if (a < b && t[n][1] - t[n - 1][1] != 1) yes = 0;
		if (!yes || a == b) continue;
		ans.push_back({ max(a,b),i });
	}
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}