/*
	if we can find a = b & b = c or a = b & c = d we can swap them each time and get a different sequence
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
pair<int,int> t[2005];
int freq[2005];

int main() {
	scanf("%d",&n);
	int eq = 0;
	loop(i, 0, n - 1) {
		t[i].second = i;
		scanf("%d", &t[i].first);
		freq[t[i].first]++;
		if (freq[t[i].first] > 1) eq++;
	}
	if (eq < 2) {
		printf("NO");
		return 0;
	}
	sort(t, t + n);
	printf("YES\n");
	loop(i, 0, n - 1)
		printf("%d ",t[i].second + 1);
	puts("");
	int idx = -1;
	loop(i, 0, n - 1) {
		if (i != n - 1 && t[i].first == t[i + 1].first && idx == -1) {
			swap(t[i], t[i + 1]);
			idx = i;
		}
		printf("%d ", t[i].second + 1);
	}
	puts("");
	loop(i, 0, n - 1) {
		if (i != n - 1 && t[i].first == t[i + 1].first && idx != i) {
			swap(t[i], t[i + 1]);
			idx = i;
		}
		printf("%d ", t[i].second + 1);
	}
}