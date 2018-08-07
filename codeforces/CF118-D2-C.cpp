/*
	brute force for 0 to 9 digit
	get the min lexicographical ans with the help of sorting
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

/*18:50*/

pair<int, int> t[N];
int ans[N];
int n, k;
int comp;
int t2[N];

bool compare(pair<int,int> &i,pair<int,int> &j) {
	if (abs(i.first - comp) == abs(j.first - comp)) { 
		if (i.first == j.first) { // two cases when a[i] == a[j]
			if (i.first > comp) return i.second < j.second; // if we will reduce the number then we take the closest index
			else return i.second > j.second; // otherwise take the farest index
		}
		else return i.first > j.first; // we take the greater number to reduce it
	}
	else return abs(i.first - comp) < abs(j.first - comp); // sort by difference
}

int main() {
	cin >> n >> k;
	loop(i, 0, n - 1) {
		char c;
		cin >> c;
		t[i].first = c - '0';
		t[i].second = i;
		ans[i] = t[i].first;
	}
	int mn = oo,to;
	loop(j, 0, 9) {
		comp = j;
		sort(t, t + n, compare);
		int curr = 0;
		loop(i, 0, k - 1) {
			curr += abs(j - t[i].first);
			t2[t[i].second] = j;
		}
		loop(i, k, n - 1) {
			t2[t[i].second] = t[i].first;
		}
		bool yes = 0;
		if (mn == curr) {
			yes = 1;
			loop(i, 0, n - 1) {
				if (t2[i] == ans[i]) continue;
				if (t2[i] < ans[i]) break;
				yes = 0;
				break;
			}
		}
		if (curr < mn || yes) {
			loop(i, 0, n - 1)
				ans[i] = t2[i];
			mn = curr;
			to = j;
		}
	}
	cout << mn << endl;
	loop(i, 0, n - 1)
		cout << ans[i];
}