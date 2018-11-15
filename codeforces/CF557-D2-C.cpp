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
int cnt[205];
pair<int,int> t[N];

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1)
		scanf("%d", &t[i].first);
	int total = 0;
	loop(i, 0, n - 1) {
		scanf("%d", &t[i].second);
		total += t[i].second;
	}
	sort(t, t + n);
	int ans = oo;
	loop(i, 0, n - 1) {
		vector<int> tmp;
		int freq = 0;
		int sum = total;
		while (i < n - 1 && t[i].first == t[i + 1].first) {
			sum -= t[i].second;
			tmp.push_back(t[i].second);
			i++;
			freq++;
		}
		sum -= t[i].second;
		tmp.push_back(t[i].second);
		loop2(j, 200, 1) {
			if (freq > cnt[j]) {
				sum -= j * cnt[j];
				freq -= cnt[j];
			}
			else {
				sum -= freq * j;
				break;
			}
		}
		ans = min(ans, sum);
		for (int j = 0; j < tmp.size(); j++)
			cnt[tmp[j]]++;
	}
	printf("%d",ans);
}