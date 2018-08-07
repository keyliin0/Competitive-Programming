/*
	determine each subsegment which is a correct bracket sequence and merge them if R2 + 1 = L2 : [L1,R1] [L2,R2] 
	and get the max ans
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
string a;
bool can[N];

int main() {
	cin >> a;
	stack<pair<char, int>> s;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ')' || a[i] == ']') {
			if (s.empty()) continue;
			if ((s.top().first == '(' && a[i] == ']') || (s.top().first == '[' && a[i] == ')')) {
				while (!s.empty()) s.pop();
				continue;
			}
			can[i] = 1;
			can[s.top().second] = 1;
			s.pop();
		}
		else s.push({ a[i],i });
	}
	int ans = 0,curr = 0;
	string output = "", tmp = "";
	for (int i = 0; i < a.size(); i++) {
		if (!can[i]) {
			if (curr > ans) {
				ans = curr;
				output = tmp;
			}
			tmp = "";
			curr = 0;
		}
		else {
			tmp += a[i];
			if (a[i] == '[') curr++;
		}
	}
	if (curr > ans) {
		ans = curr;
		output = tmp;
	}
	cout << ans << endl << output;
}