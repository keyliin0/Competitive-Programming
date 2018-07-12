/*
	an easy brute force solution is to make two for loops for the range L,R and another one to calculate the sum
	and check if we can remove k minimum numbers and replace them with maximum non used numbers if possible
	but this is o(n^3) regardless the checking for the unused numbers
	we can optimize this solution so we use two loops inside a loop
	the first big loop will try every possible L
	and the second one will store all the numbers in a set
	the third one will start from L to N and calculate the sum and in the same time check if we can replace the first min K numbers with 
	bigger unused numbers
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

int n, k;
int t[300];


int main() {
	scanf("%d%d", &n, &k);
	loop(i, 0, n - 1)
		scanf("%d", &t[i]);
	int ans = -oo;
	for (int i = 0; i < n; i++) {
		multiset<int> s;
		for (int j = 0; j < n; j++)
			s.insert(t[j]);
		priority_queue<int> q;
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += t[j];
			s.erase(s.find(t[j]));
			q.push(-t[j]);
			ans = max(ans, sum);
			queue<int> tmp, tmp2;
			int tmp_sum = sum;
			for (int x = 0; x < k && s.size() && q.size(); x++) {
				if (-q.top() >= *(--s.end())) break;
				auto it = --s.end();
				tmp.push(*it);
				tmp2.push(-q.top());
				tmp_sum -= -q.top();
				tmp_sum += *it;
				q.pop();
				s.erase(it);
				ans = max(ans, tmp_sum);
			}
			while (!tmp.empty()) {
				s.insert(tmp.front());
				tmp.pop();
			}
			while (!tmp2.empty()) {
				q.push(-tmp2.front());
				tmp2.pop();
			}
		}
	}
	printf("%d", ans);
}