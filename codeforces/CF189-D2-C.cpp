/*
	starting from 1 to n 
	if we p1[i] != p2[i] then we must remove some elements from the end until we find p2[i]  (and save the elements we removed)
	if we already removed p2[i] and p1[i] != p2[i] then we dont need to make any move since we know how to place an element optimally
	when we remove it
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
const int oo = 1e9 + 9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

deque<int> q;
int t[N];
bool vis[N];
int n;

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		int a;
		scanf("%d",&a);
		q.push_back(a);
	}
	loop(i, 0, n - 1)
		scanf("%d",&t[i]);
	int ans = 0;
	loop(i, 0, n - 1) {
		if (vis[t[i]]) continue;
		if (t[i] == q.front()) {
			q.pop_front();
			continue;
		}
		while (q.back() != t[i]) {
			vis[q.back()] = 1;
			ans++;
			q.pop_back();
		}
		ans++;
		q.pop_back();
	}
	printf("%d",ans);
}