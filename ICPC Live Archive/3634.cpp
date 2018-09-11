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

map < set<int>, int > id;
vector<set<int> > v;
stack<int> st;
int n;

int getid(set<int> s){
	if (!id.count(s)){
		v.push_back(s);
		id[s] = v.size() - 1;
	}

	return id[s];
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		cin >> n;
		while (n--) {
			string s;
			cin >> s;
			if (s == "PUSH") st.push(getid(set<int>()));
			else if (s == "DUP") st.push(st.top());
			else {
				set<int> a, b, res;
				a = v[st.top()];
				st.pop();
				b = v[st.top()];
				st.pop();
				if (s == "UNION") {
					set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
					st.push(getid(res));
				}
				else if (s == "INTERSECT") {
					set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
					st.push(getid(res));
				}
				else{
					b.insert(id[a]);
					st.push(getid(b));
				}
			}
			printf("%d\n",v[st.top()].size());
		}
		printf("***\n");
	}
}