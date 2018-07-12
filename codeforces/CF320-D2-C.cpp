/*
	http://codeforces.com/blog/entry/8166
*/
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

string x;
ll res[105];

ll fastPower(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res * res) % mod * a) % mod;
	return (res*res) % mod;
}

int main() {
	cin >> x;
	reverse(x.begin(), x.end());
	if (x[0] == '0') res[0] = 0;
	else res[0] = 1;
	for (int i = 1; i < x.size(); i++) {
		if (x[i] == '0') res[i] = (2 * res[i - 1]) % mod;
		else res[i] = ((2 * res[i - 1])  + fastPower(2,i * 2)) % mod;
	}
	cout << res[x.size() - 1];
}