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


struct Point{
	int x,y;
};

Point t[3];

bool check(int i,int j,int k){
	return (  t[i].x == t[j].x  && (max(t[i].y,t[j].y) <= t[k].y || min(t[i].y,t[j].y) >= t[k].y) ) || (  t[i].y == t[j].y  && (max(t[i].x,t[j].x) <= t[k].x || min(t[i].x,t[j].x) >= t[k].x) );
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	loop(i,0,2){
		scanf("%d%d",&t[i].x,&t[i].y);
	}
	if( (t[0].x == t[1].x && t[1].x == t[2].x) || (t[0].y == t[1].y && t[1].y == t[2].y) ){
		printf("1");
		return 0;
	}
	if ( check(0,1,2) || check(1,2,0) || check(0,2,1) ){
		printf("2");
		return 0;
	}
	printf("3");
}