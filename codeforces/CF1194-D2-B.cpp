/* 
	iterate through all rows and columns the answer is n + m - num of black cells in this row - num of black cells in this col 
	there is a case where there is a white cell in the intersection of the row and colum in this case the answer is : 
	n + m - num of black cells in this row - num of black cells in this col  - 1
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
 
int q, n, m;
int col[(int)1e5];
int row[(int)1e5];
 
int main() {
	io;
	cin >> q;
	while (q--) {
		cin >> n >> m;
		memset(col, 0, sizeof col);
		memset(row, 0, sizeof row);
		vector<string> s;
		s.resize(n);
		loop(i, 0, n - 1) {
			cin >> s[i];
			loop(j, 0, m - 1) {
				row[i] += s[i][j] == '*';
				col[j] += s[i][j] == '*';
			}
		}
		int ans = oo;
		loop(i, 0, n - 1) {
			loop(j, 0, m - 1) {
				ans = min(ans, n + m - row[i] - col[j] - (s[i][j] != '*'));
			}
		}
		cout << ans << "\n";
	}
}