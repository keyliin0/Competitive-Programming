/*
	any number can expressed as a summation of 4 primes (not the case for 2 or 1).
	we can use that to make a binary search for the first prime number that is the closest to the distance (i - j + 1)
	since we know that any number can be expressed as a summation of 4 primes , for the worst case we will make 4 binary search to find our final index
	start placing numbers from 1 to n so we make sure every number take its place will not be moved again
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

bool prime[N];
int t[N], idx[N];
int n;
vector<pair<int, int> > ans;
vector<int> v;


void generateprime(int n) {
	memset(prime, 1, sizeof prime);
	for (int i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) v.push_back(i);
	}
}

int main() {
	generateprime(1e5);
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		int a;
		scanf("%d",&a);
		t[a] = i + 1;
		idx[i + 1] = a;
	}
	loop(i, 1, n) {
		while (t[i] != i) {
			auto it = lower_bound(v.begin(), v.end(), t[i] - i + 1);
			if (it == v.end()) it--;
			else if (*it > t[i] - i + 1) it--;
			int j = t[i] - *it + 1;
			ans.push_back({ j,t[i] });
			int tmp1 = j, tmp2 = t[i], tmp3 = i, tmp4 = idx[j];
			t[i] = tmp1;
			t[tmp4] = tmp2;
			idx[j] = tmp3;
			idx[tmp2] = tmp4;
		}
	}
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}