/*
	we must factorize each number as much as possible , that can be done using prime factorization
	going through all the numbers from 2 to 10^6 and counting the factors of each one will TL
	but since we are going in an increasing order we know number factors of an integer x = 1 + number of factors of x / i 
	i is the first number such that x % i = 0
	use prefix sum to answer each test case in o(1)
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
int freq[N];

void getfactors(int x) {
	int sum = 0,a = x;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			freq[a] = 1 + freq[x / i];
			return;
		}
	}
	freq[a] = 1;
}

int main() {
	loop(i, 2, 1e6)
		getfactors(i);
	loop(i, 2, 1e6)
		freq[i] += freq[i - 1];
	while (scanf("%d", &n) != EOF) {
		ll ans = freq[n];
		printf("%lld\n",ans);
	}
}
