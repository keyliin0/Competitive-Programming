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

string s;
int f[N],freq[N];
int n;

void calc() {
	int len = 0;
	//cout << "0 ";
	for (int i = 1; i < s.size(); i++) {
		while (len > 0 && s[i] != s[len])
			len = f[len - 1];
		if (s[i] == s[len])
			len++;
		f[i] = len;
		//cout << f[i] << " ";
	}
}

int main() {
	cin >> s;
	calc();
	for (int i = 0; i < s.size(); i++)
		freq[f[i]]++;
	for (int i = s.size() - 1; i > 0; i--)
		freq[f[i - 1]] += freq[i];
	vector<pair<int, int> > ans;
	int k = f[s.size() - 1];
	ans.push_back({ s.size() , 1 });
	while (k > 0) {
		ans.push_back({ k , freq[k] + 1 });
		k = f[k - 1];
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
}