#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

string s;

bool compare(string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	return a >= b;
}

int main() {
	io;
	cin >> s;
	vector<string> v;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		tmp += s[i];
		if (i < s.size() - 1 && s[i + 1] == '0') continue;
		v.push_back(tmp);
		tmp = "";
	}
	tmp = v[0];
	int ans = 1;
	for (int i = 1; i < v.size(); i++) {
		if (compare(tmp, v[i])) ans++;
		else ans = 1;
		tmp += v[i];
	}
	cout << ans;
}