/*
	we store the frequency and the last occ of the number in an array
	we run over the left most number and check if we can get a segment with more beauty (frequency)
	and if it's equal to the max we compare the distance
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
int t[N], freq[N], R[N];

int main() {
	scanf("%d",&n);
	loop(i, 0, n - 1) {
		scanf("%d",&t[i]);
		freq[t[i]]++;
		R[t[i]] = i;
	}
	int mx = -1, l, r;
	loop(i, 0, n - 1) {
		if (freq[t[i]] == -1) continue;
		if (freq[t[i]] > mx || (freq[t[i]] == mx && R[t[i]] - i < r - l)) {
			l = i, r = R[t[i]];
			mx = freq[t[i]];
		}
		freq[t[i]] = -1;
	}
	printf("%d %d", l + 1, r + 1);
}