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
map<string, int> mp;
bool adj[200][200];
vector<string> v;

int main() {
	io;
	int test = 0;
	while(1){
		mp.clear();
		v.clear();
		cin >> n;
		if (n == 0) break;
		memset(adj, 0, sizeof adj);
		int cnt = 0;
		loop(i, 0, n - 1) {
			int m;
			cin >> m;
			loop(j, 0, m - 1) {
				string s;
				cin >> s;
				v.push_back(s);
				mp[s] = cnt;
				cnt++;
			}
			loop(j, cnt - m, cnt - 2) {
				adj[j][j + 1] = 1;
			}
		}
		int q;
		cin >> q;
		loop(i, 0, q - 1) {
			string s1, s2;
			cin >> s1 >> s2;
			adj[mp[s1]][mp[s2]] = 1;
		}
		for (int k = 0; k < cnt; k++)
			for (int i = 0; i < cnt; i++)
				for (int j = 0; j < cnt; j++)
					adj[i][j] |= adj[i][k] & adj[k][j];
		vector<pair<string,string>> ans;
		for (int i = 0; i < cnt; i++)
			for (int j = i + 1; j < cnt; j++)
				if (!adj[i][j] && !adj[j][i])
					ans.push_back({ v[i],v[j] });
		test++;
		if (ans.size()) {
			cout << "Case " << test << ", " << ans.size() << " concurrent events:" << endl;
			for (int i = 0; i < 2 && i < ans.size(); i++)
				cout << "(" << ans[i].first << "," << ans[i].second << ") ";
			cout << endl;
		} else
			cout << "Case " << test << ", no concurrent events." << endl;
	}
}