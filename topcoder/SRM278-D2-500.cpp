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
const double EPS = 1e-18;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

class BestTriangulation {
public:
	double maxArea(vector<string> vertices) {
		vector<point> v;
		for (int i = 0; i < vertices.size(); i++) {
			istringstream iss(vertices[i]);
			double x, y;
			iss >> x;
			iss >> y;
			v.push_back(point(x, y));
		}
		double ans = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				for (int k = j + 1; k < v.size(); k++) {
					double curr = cp(v[i], v[j]) + cp(v[j], v[k]) + cp(v[k], v[i]);
					curr = fabs(curr/2.0);
					ans = max(ans, curr);
				}
			}
		}
		return ans;
	}
};