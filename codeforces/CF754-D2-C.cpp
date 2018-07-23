/*
	give every user an id so we can manipulate the input easier
	split every word in every message and check if it mention any user
	brute force to check if a solution exists and memo
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

int n,m;
string u[101];
map<string, int> user;
string msg[101];
int sentby[101];
bool mention[101][101];
int dp[105][105];

int solve(int i,int last) {
	if (i == m)
		return 1;
	int &ret = dp[i][last];
	if (ret != -1) return ret;
	ret = 0;
	if (sentby[i] == last) return 0;
	if (sentby[i] != 0) return ret = solve(i + 1, sentby[i]);
	for (int j = 1; j <= n && !ret; j++)
		if (last != j && !mention[i][j]) ret = solve(i + 1, j);
	return ret;
}

void build(int i, int last) {
	if (i == m) return;
	if (sentby[i] != 0) {
		cout << u[sentby[i]] << ":";
		cout << msg[i] << endl;
		build(i + 1, sentby[i]);
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (last != j && !mention[i][j] && solve(i, last) == solve(i + 1, j)) {
			cout << u[j] << ":";
			cout << msg[i] << endl;
			build(i + 1, j);
			return;
		}
	}
}

int main() {
	io;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		user.clear();
		loop(i, 1, n) {
			cin >> u[i];
			user[u[i]] = i;
		}
		user["?"] = 0;
		cin >> m;
		cin.ignore();
		memset(mention, 0, sizeof mention);
		loop(i, 0, m - 1) {
			string message;
			getline(cin, message);
			string tmp1 = "", tmp2 = "", username = "";
			bool us = 0;
			int idx = 0;
			while (message[idx] != ':') username += message[idx], idx++;
			for (int j = idx + 1; j < message.size(); j++) {
				tmp2 += message[j];
				if (((char)toupper(message[j]) >= 'A' && (char)toupper(message[j]) <= 'Z') || (message[j] >= '0' && message[j] <= '9'))
					tmp1 += message[j];
				else {
					mention[i][user[tmp1]] = 1;
					tmp1 = "";
				}
			}
			if (tmp1 != "") mention[i][user[tmp1]] = 1;
			msg[i] = tmp2;
			sentby[i] = user[username];
		}
		memset(dp, -1, sizeof dp);
		int sol = solve(0, 103);
		if (sol) build(0, 103);
		else cout << "Impossible" << endl;
	}
}
