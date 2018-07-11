/*
	we can make each row in the matrix alternate between 1s and 0s
	it's clear that n must be odd or we have a problem of symmetry between the two rows in the middle
	x = 3 is a corner case and we must deal with it
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

int x;

int main() {
	scanf("%d",&x);
	if (x == 3) {
		printf("5");
		return 0;
	}
	for (int i = 1; i < 1000; i += 2) {
		int x1 = (i / 2) * (i / 2), x2 = (i / 2) * ((i + 1) / 2),x3 = (i / 2) + 1;
		if (x1 + x2 + x3 >= x) {
			printf("%d",i);
			return 0;
		}
	}
}