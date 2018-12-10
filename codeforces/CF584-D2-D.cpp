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

int n;
bool prime[N];
vector<int> v;

void generateprime(int n) {
	int i;
	for (i = 0; i <= n; i++)
		prime[i] = true;
	for (i = 2; i*i <= n; i++)
		if (prime[i] == true)
			for (int j = i; i*j <= n; j++)
				prime[i*j] = false;
	for (i = 2; i <= n; i++)
		if (prime[i]) v.push_back(i);
}

bool is_prime(int n) {
	bool is_prime = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) is_prime = 0;
	}
	return is_prime;
}

int main() {
	scanf("%d",&n);
	generateprime(min(10000, n));
	if (is_prime(n)) {
		printf("1\n%d",n);
		return 0;
	}
	for (int i = 1; i < v.size(); i++) {
		int curr = n - 2 - v[i];
		if (curr == 0) {
			printf("2\n2 %d", v[i]);
			return 0;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		int curr = n - 4 - v[i];
		if (curr == 0) {
			printf("3\n2 2 %d", v[i]);
			return 0;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		for (int j = 1; j < v.size(); j++) {
			int curr = n - v[j] - v[i];
			if (curr > 0 && is_prime(curr)) {
				printf("3\n%d %d %d", v[i], v[j], curr);
				return 0;
			}
		}
	}
}