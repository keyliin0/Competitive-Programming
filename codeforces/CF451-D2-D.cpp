/*
	observation : 
	ababababa... is palindrome only if the length of such string is odd
	
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

char s[N];
int even[2], odd[2];

int main() {
	scanf("%s",s);
	int n = strlen(s);
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || s[i] != s[i - 1]) curr++;
		if (i % 2 == 0) even[curr % 2]++;
		else odd[curr % 2]++;
	}
	curr = 0;
	ll ans_even = 0,ans_odd = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || s[i] != s[i - 1]) curr++;
		if (i % 2 == 0) {
			ans_even += odd[curr % 2];
			ans_odd += even[curr % 2];
			even[curr % 2]--;
		}
		else {
			ans_odd += odd[curr % 2];
			ans_even += even[curr % 2];
			odd[curr % 2]--;
		}
	}
	printf("%lld %lld",ans_even,ans_odd);
}