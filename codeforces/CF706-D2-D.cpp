/*
	we know that 2^n > sum of powers of two such that p < n
	so to maximize try make the bits 1 and 0 otherwise starting from the most significant bit
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

int q;
vector<vector<int>> v;
vector<vector<int>> freq;
int ans;

void insert(int x) {
	int curr = 0;
	for (int i = 31; i >= 0; i--) {
		int bit = ((1 << i) & x) ? 1 : 0;
		if (v[curr][bit] == -1) {
			v[curr][bit] = v.size();
			freq.push_back(vector<int>(2, 0));
			v.push_back(vector<int>(2, -1));
		}
		freq[curr][bit]++;
		curr = v[curr][bit];
	}
}

void erase(int x) {
	int curr = 0;
	for (int i = 31; i >= 0; i--) {
		int bit = ((1 << i) & x) ? 1 : 0;
		freq[curr][bit]--;
		curr = v[curr][bit];
	}
}

void find(int x) {
	int curr = 0;
	ans = 0;
	for (int i = 31; i >= 0; i--) {
		int bit = ((1 << i) & x) ? 1 : 0;
		if (bit == 1) {
			if (freq[curr][0]) {
				ans += (1 << i);
				curr = v[curr][0];
			}
			else curr = v[curr][1];
		}
		else {
			if (freq[curr][1]) {
				ans += (1 << i);
				curr = v[curr][1];
			}
			else curr = v[curr][0];
		}
	}
}

int main() {
	io;
	cin >> q;
	v.push_back(vector<int>(2, -1));
	freq.push_back(vector<int>(2, 0));
	insert(0);
	while (q--) {
		char c;
		int n;
		cin >> c >> n;
		if (c == '+') insert(n);
		else if (c == '-') erase(n);
		else {
			find(n);
			cout << ans << "\n";
		}
	}
}