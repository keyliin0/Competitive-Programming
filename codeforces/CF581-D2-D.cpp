/*
	brute force for n 
	to check if the logos fit in the square try to fix one of the logos each time at the top left corner of the square , do the same for the bottom right corner
	now check if the last logo can fit in the square without leaving an empty cell
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

pair<int, int> t[5];
bool vis[4];
bool sol;
char g[350][350];
vector<int> cords;

void PRINT(int x) {
	cout << cords[1] + 1 << endl;
	for (int i = 0; i <= cords[1]; i++) {
		for (int j = 0; j <= cords[1]; j++) {
			if (g[i][j] == '-') cout << char('A' + x);
			else cout << g[i][j];
		}
		cout << endl;
	}
}

void backtrack(int cnt) {
	if (sol) return;
	if (cnt == 2) {
		int c;
		for (int i = 0; i < 3; i++)
			if (!vis[i]) c = i;
		int x = -1, y = -1, empty = 0;
		for (int i = 0; i <= cords[1]; i++) {
			for (int j = 0; j <= cords[1]; j++) {
				if (g[i][j] == '-') {
					if (x == -1) x = i, y = j;
					empty++;
				}
			}
		}
		if (x == -1 || empty != t[c].first * t[c].second) return;
		empty = 0;
		bool yes = 1;
		for (int i = x; i < x + t[c].first && i <= cords[1]; i++) {
			for (int j = y; j < y + t[c].second && j <= cords[1]; j++) {
				if (g[i][j] != '-') yes = 0;
				else empty++;
			}
		}
		if (empty != t[c].first * t[c].second) yes = 0;
		if (yes) {
			PRINT(c);
			sol = 1;
			return;
		}
		yes = 1;
		empty = 0;
		for (int i = x; i < x + t[c].second && i <= cords[1]; i++) {
			for (int j = y; j < y + t[c].first && j <= cords[1]; j++) {
				if (g[i][j] != '-') yes = 0;
				else empty++;
			}
		}
		if (empty != t[c].first * t[c].second) yes = 0;
		if (yes) {
			PRINT(c);
			sol = 1;
			return;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (cnt == 0) {
			for (int row = cords[cnt]; row < t[i].first; row++) {
				for (int col = cords[cnt]; col < t[i].second; col++) {
					g[row][col] = 'A' + i;
				}
			}
			backtrack(cnt + 1);
			for (int row = cords[cnt]; row < t[i].first; row++) {
				for (int col = cords[cnt]; col < t[i].second; col++) {
					g[row][col] = '-';
				}
			}
			for (int row = cords[cnt]; row < t[i].second; row++) {
				for (int col = cords[cnt]; col < t[i].first; col++) {
					g[row][col] = 'A' + i;
				}
			}
			backtrack(cnt + 1);
			for (int row = cords[cnt]; row < t[i].second; row++) {
				for (int col = cords[cnt]; col < t[i].first; col++) {
					g[row][col] = '-';
				}
			}
		}
		else {
			bool yes = cords[cnt] - t[i].first + 1 >= 0 && cords[cnt] - t[i].second + 1 >= 0;
			for (int row = cords[cnt]; row > cords[cnt] - t[i].first && yes; row--) {
				for (int col = cords[cnt]; col > cords[cnt] - t[i].second; col--) {
					if (g[row][col] == '-') g[row][col] = 'A' + i;
					else yes = 0;
				}
			}
			if (yes) backtrack(cnt + 1);
			for (int row = cords[cnt]; row > cords[cnt] - t[i].first && row >= 0; row--) {
				for (int col = cords[cnt]; col > cords[cnt] - t[i].second && col >= 0; col--) {
					if (g[row][col] = 'A' + i) g[row][col] = '-';
				}
			}
			yes = cords[cnt] - t[i].second + 1 >= 0 && cords[cnt] - t[i].first + 1 >= 0;
			for (int row = cords[cnt]; row > cords[cnt] - t[i].second && yes; row--) {
				for (int col = cords[cnt]; col > cords[cnt] - t[i].first; col--) {
					if (g[row][col] == '-') g[row][col] = 'A' + i;
					else yes = 0;
				}
			}
			if (yes) backtrack(cnt + 1);
			for (int row = cords[cnt]; row > cords[cnt] - t[i].second && row >= 0; row--) {
				for (int col = cords[cnt]; col > cords[cnt] - t[i].first && col >= 0; col--) {
					if (g[row][col] = 'A' + i) g[row][col] = '-';
				}
			}
		}
		vis[i] = 0;
	}
}

int main() {
	loop(i, 0, 2)
		scanf("%d%d", &t[i].first, &t[i].second);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			g[i][j] = '-';
		}
	}
	for (int i = 0; i < 100; i++) {
		cords.clear();
		cords.push_back(0);
		cords.push_back(i);
		backtrack(0);
	}
	if (!sol) cout << -1;
}