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

int dp[5001][5001][2];
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    char s[5001];
    for(int i = 0;i < n; i++){
        scanf("%s",s);
        dp[i][m - 1][0] = s[m - 1] == '1';
        for(int j = m - 2;j >= 0; j--){
            if(s[j] == '0') continue;
            dp[i][j][0] = 1 + dp[i][j + 1][0];
        }
    }
    for(int j = 0;j < m; j++)
        for(int i = 0;i < n; i++)
            dp[j][dp[i][j][0]][1]++;
    for(int j = 0;j < m;j++)
        for(int i = n - 2;i >= 0; i--)
            dp[j][i][1] += dp[j][i + 1][1];
    int ans = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            ans = max(ans, dp[i][j][0] * dp[j][dp[i][j][0]][1]);
    printf("%d",ans);
}