/* 
	observation : if a prime number x > 2 exist and x * 2 <= length of the string then s[x] must be equal to s[2] and so on
	a greedy way to check for a solution is to take caracter which has the max frequency and check if we can make 
	all positions of multiples of two equal the same caracter and then we check the other postion where x > 2 and x * 2 <= length of the string
	the other postions can take any caracter
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

int freq[30];
string s;

int main() {
	io;
	cin >> s;
	char cmx = 'a';
	loop(i, 0, s.size() - 1) {
		freq[s[i] - 'a']++;
		if (freq[cmx - 'a'] < freq[s[i] - 'a']) 
			cmx = s[i];
		s[i] = '?';
	}
	bool yes = 1;
	for (int i = 1; i < s.size() && yes; i++) {
		if (s[i] != '?' || (i + 1) * 2 > s.size()) continue;
		for (int j = i; j < s.size(); j += (i + 1)) {
			if (s[j] != '?') continue;
			if (freq[cmx - 'a'] == 0) {
				yes = 0;
				break;
			}
			freq[cmx - 'a']--;
			s[j] = cmx;
		}
	}
	if (!yes) {
		cout << "NO";
		return 0;
	}
	char j = 'a';
	loop(i, 0, s.size() - 1) {
		if (s[i] != '?') continue;
		while (freq[j - 'a'] == 0) j++;
		freq[j - 'a']--;
		s[i] = j;
	}
	cout << "YES" << endl << s;
}
