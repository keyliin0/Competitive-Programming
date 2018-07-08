/*
	This solution, although it might look like depending on the initial directions of the balls, 
	only depends on the pair-wise interactions between balls. 
	For each pair of balls that will collide during the T seconds, 
	there is one configuration out of four configurations that will have the direction conditions 
	for collisions true (that this pair of balls is heading towards each other). 
	So, looping over all direction configurations is unnecessary and can be replaced by a solution that counts each pair of balls colliding only once as 1/4 expected collisions.
	http://apps.topcoder.com/wiki/display/tc/Member+SRM+458
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

class BouncingBalls {
public:
	double expectedBounces(vector<int> v, int t) {
		double ans = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			for (int j = i + 1; j < v.size(); j++)
				if (v[i] + t >= v[j] - t)
					ans += 0.25;
		return ans;
	}
	
};

