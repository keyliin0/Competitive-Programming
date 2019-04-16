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

int n;
map<int, int> freq;
int t[1005];

int main() {
	scanf("%d", &n);
	loop(i, 0, n - 1) {
		scanf("%d", &t[i]);
		freq[t[i]]++;
	}
	int ans = freq[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || t[i] == t[j] && t[i] == 0) continue;
			int len = 2;
			vector<int> v;
			int f1 = t[i] + t[j];
			int f0 = t[j];
			freq[t[j]]--;
			freq[t[i]]--;
			v.push_back(t[i]);
			v.push_back(t[j]);
			while (freq[f1]) {
				freq[f1]--;
				v.push_back(f1);
				int tmp = f1;
				f1 = f1 + f0;
				f0 = tmp;
				len++;
			}
			while (v.size()) {
				int u = v.back();
				v.pop_back();
				freq[u]++;
			}
			ans = max(ans, len);
		}
	}
	printf("%d",ans);
}