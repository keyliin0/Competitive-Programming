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
const double EPS = 1e-8;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
ll t[N];

int main() {
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%lld",&t[i]);
    ll cnt = 0;
    printf("%d\n",n + 1);
    for(int i = n - 1;i >= 0;i--){
        ll ans;
        for(ll x = 0;x <= n;x++)
            if((t[i] + cnt + x) % n == i){
                ans = x;
                break;
            }
        cnt += ans;
        printf("1 %d %lld\n",i + 1,ans);
    }
    printf("2 %d %d",n,n);
}