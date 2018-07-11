/* 
	if s[i] = s[i - 1] || s[i] = s[i + 1] then s[i] will not change
	if we try few cases we can see that a fixed segment will never
	a segment or sub string will change and alternate (L + 1) / 2 time and will be fixed. L is the length of the segment
	we know a segment will change if s[i] != s[i - 1] && s[i] != s[i + 1]
	so the answer will be the length of the longest alternating segment Lmax + 1  / 2
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

int n;
char s[N];

void change(int l,int r) {
	char cl = s[l - 1], cr = s[r + 1];
	while (l <= r) {
		s[l] = cl;
		s[r] = cr;
		r--;
		l++;
	}
}

int main() {
	io;
	cin >> n;
	loop(i, 0, n - 1)
		cin >> s[i];
	int len = 0,curr = 0;
	int l = -1, r = -1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			curr++;
			if (l == -1) l = i + 1;
		}
		else {
			if (l != -1) {
				r = i - 1;
				change(l, r);
			}
			len = max(len, curr);
			curr = 0;
			l = -1, r = -1;
		}
	}
	len = max(len, curr);
	if (l != -1 && r == -1) {
		r = n - 2;
		change(l, r);
	}
	cout << len / 2 << endl;
	loop(i, 0, n - 1)
		cout << s[i] << " ";
}