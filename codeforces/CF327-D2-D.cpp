/*
	if we represent the grid as a graph , we can see that we must first fill the nodes in the last layer or depth with red buildings 
	and to do that we must fill the nodes above this layer with blue buildings , now do the same for the previous layer and so on
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

int n, m;
char g[501][501];
bool vis[501][501];
vector<pair<char,pair<int, int>> > ans;

void dfs(int i,int j,bool p) {
	vis[i][j] = 1;
	ans.push_back({ 'B',{i,j} });
	loop(k, 0, 3) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '.' &&  !vis[nx][ny]) {
			dfs(nx, ny, 1);
		}
	}
	if (p) {
		ans.push_back({ 'D', {i,j} });
		ans.push_back({ 'R', {i,j} });
	}
}

int main() {
	io;
	cin >> n >> m;
	loop(i, 0, n - 1)
		loop(j, 0, m - 1)
			cin >> g[i][j];
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			if (!vis[i][j] && g[i][j] == '.') dfs(i, j, 0);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << "\n";
	}
}
