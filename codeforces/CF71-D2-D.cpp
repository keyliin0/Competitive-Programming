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
char ranks[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' ,'A' };
char suits[] = { 'C', 'D', 'H' ,'S' };
map<string, bool> mp;
bool sol;
vector<pair<int, int> > v;
string g[20][20];
vector<pair<int, int> > cords;
vector<string> rep;
vector<char> jk;


bool can(int i, int j, int xx, int yy) {
	if (i + 2 >= n || j + 2 >= m) return 0;
	map<char, bool> vis_ranks;
	bool rank = 1, suit = 1;
	char s = g[i][j][1];
	loop(x, i, i + 2) {
		loop(y, j, j + 2) {
			if (x >= xx && x <= xx + 2 && y >= yy && y <= yy + 2) return 0;
			if (vis_ranks[g[x][y][0]]) rank = 0;
			vis_ranks[g[x][y][0]] = 1;
			if (s != g[x][y][1]) suit = 0;
		}
	}
	return suit | rank;
}

void check(int x,int y) {
	if (cords.size() == 2) {
		sol = 1;
		return;
	}
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			if (i >= x && i <= x + 2 && j >= y && j <= y + 2) continue;
			if (can(i, j,x,y)) {
				cords.push_back({ i,j });
				check(i, j);
				if (sol) return;
				cords.pop_back();
			}
		}
	}
}

void backtrack(int idx) {
	if (idx == v.size()) {
		check(999,999);
		return;
	}
	loop(i,0,12)
		loop(j, 0, 3) {
			string s = "";
			s += ranks[i];
			s += suits[j];
			if (mp[s]) continue;
			mp[s] = 1;
			g[v[idx].first][v[idx].second] = s;
			backtrack(idx + 1);
			if (sol) {
				rep.push_back(s);
				return;
			}
			mp[s] = 0;
	}
}

int main() {
	cin >> n >> m;
	loop(i,0,n-1){
		loop(j, 0, m - 1) {
			cin >> g[i][j];
			mp[g[i][j]] = 1;
			if (g[i][j][0] == 'J' && (g[i][j][1] == '1' || g[i][j][1] == '2')) {
				v.push_back({ i,j });
				jk.push_back(g[i][j][1]);
			}
		}
	}
	if (jk.size() == 2) {
		if (jk[0] == '2') swap(jk[0], jk[1]), swap(v[0], v[1]);
	}
	backtrack(0);
	if (!sol) {
		printf("No solution.");
		return 0;
	}
	printf("Solution exists.\n");
	if (!v.size()) printf("There are no jokers.\n");
	else if (v.size() == 1) cout << "Replace J"<< jk[0]<<" with " << rep[0] << "." << endl;
	else cout << "Replace J" << jk[0] << " with " << rep[1] << " and J"<< jk[1] <<" with " << rep[0] << "." << endl;
	printf("Put the first square to (%d, %d).\n", cords[0].first + 1, cords[0].second + 1);
	printf("Put the second square to (%d, %d).", cords[1].first + 1, cords[1].second + 1);
}
