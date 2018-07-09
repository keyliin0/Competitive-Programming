/*
	if we try the first n < 6 cases we can see that we can't make the algorithm give a wrong answer
	when we have more than 5 nodes we can connect node 2,3,4 to 1 and all other nodes to 2 or 3 or 4
	the algorithm will give 3 but must give 2
	we can always build a long tree where we connect the node i to i - 1 and get always get a correct answer
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

int main() {
	scanf("%d",&n);
	if (n < 6) 
		printf("-1\n");
	else {
		printf("1 2\n1 3\n1 4\n");
		for (int i = 5; i <= n; i++) {
			printf("2 %d\n",i);
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n",i-1,i);
	}
}