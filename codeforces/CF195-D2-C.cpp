/*
	we generate all prime numbers < 10^7 then calculate prefix sum for primes and palindromes
	and we check the ans in linear time
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

const int f = 1e7 + 1;
int prime[f], pal[f];
int p, q;

int check(string x) {
	int l = 0, r = x.size() - 1;
	while (l <= r) {
		if (x[l] != x[r]) return 0;
		l++;
		r--;
	}
	return 1;
}

void generateprime(int n) {
	int i;
	for (int i = 2; i <= n; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (i = 2; i*i <= n; i++)
		if (prime[i])
			for (int j = i; i*j <= n; j++)
				prime[i*j] = 0;
	pal[1] = 1;
	for (i = 2; i <= n; i++) {
		pal[i] += pal[i - 1] + check(to_string(i));
		prime[i] += prime[i - 1];
	}
}
int main() {
	generateprime(2 * 1e6);
	scanf("%d%d", &p, &q);
	int ans = 0;
	loop(i, 1, 2 * 1e6) {
		if (pal[i] * p >= prime[i] * q) ans = i;
	}
	printf("%d",ans);
}