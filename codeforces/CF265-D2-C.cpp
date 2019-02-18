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
const double EPS = 1e-18;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

string s;
pair<int, int> t[N];

int main() {
	io;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		t[i].second = i;
	}
	int l = 1, r = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'l') t[i].first = r--;
		else t[i].first = l++;
	}
	sort(t, t + s.size());
	for (int i = 0; i < s.size(); i++)
		cout << t[i].second + 1 << "\n";
}