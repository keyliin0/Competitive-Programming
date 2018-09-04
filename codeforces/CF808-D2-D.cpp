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

ll t[N];
int n;
multiset<ll> s;

int main() {
	scanf("%d",&n);
	ll sum = 0;
	loop(i, 0, n - 1) {
		scanf("%lld",&t[i]);
		sum += t[i];
		s.insert(t[i]);
	}
	if (sum % 2 != 0) {
		printf("NO");
		return 0;
	}
	sum /= 2;
	if (n > 1 && s.find(sum) != s.end()) { // check if the prefix or suffix will be a signle element 
		printf("YES");
		return 0;
	}
	ll curr = 0;
	loop(i, 0, n - 2) { // suppose that the first element will be a prefix
		s.erase(s.find(t[i]));
		curr += t[i];
		if (curr == sum) {
			printf("YES");
			return 0;
		}
		if (i < n - 2 && s.find(sum - curr) != s.end()) {
			printf("YES");
			return 0;
		}
	}
	s.clear();
	loop(i, 0, n - 1)
		s.insert(t[i]);
	curr = 0;
	loop2(i, n - 1, 1) { // check again in case the first element can not be a prefix
		s.erase(s.find(t[i]));
		curr += t[i];
		if (curr == sum) {
			printf("YES");
			return 0;
		}
		if (i > 1 && s.find(sum - curr) != s.end()) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}