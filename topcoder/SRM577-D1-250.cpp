/*
	http://apps.topcoder.com/wiki/display/tc/SRM+577
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
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

vector<pair<ll, int> > v;
vector<double> avg;

class EllysRoomAssignmentsDiv1 {
public:
	double solve() {
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int r = (v.size() + 19) / 20;
		int elly = 0;
		for (int i = 0; i < v.size() + r; i += r) {
			ll sum = 0, cnt = 0;
			for (int j = i; j < v.size() && j < i + r; j++) {
				sum += v[j].first;
				cnt++;
				if (v[j].second == 0) {
					cnt = 1;
					elly = j;
					sum = v[j].first;
					break;
				}
			}
			if (cnt) avg.push_back((double)sum / cnt);
		}
		double ans = 0;
		int t = v.size() / r;
		for (int i = 0; i < avg.size(); i++)
			ans += avg[i];
		if (v.size() % r == 0) {
			return (double)ans / t;
		}
		else if (elly / r == t) {
			return (double)ans / (t + 1);
		}
		else {
			double p1 = (double)(v.size() % r) / r;
			double p2 = (double)1.0 - p1;
			return (double)p1 * (ans / (t + 1)) + p2 * ((ans - avg[avg.size() - 1]) / t);
		}
	}
	double getAverage(vector<string> ratings) {
		string s = "";
		for (int i = 0; i < ratings.size(); i++) {
			s += ratings[i];
		}
		ll x;
		int idx = 0;
		istringstream iss(s);
		while (iss >> x) v.push_back({ x,idx }), idx++;
		return solve();
	}

};


