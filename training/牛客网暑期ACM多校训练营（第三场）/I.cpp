#include <bits/stdc++.h>
using namespace std;
const int MN = 1000005;
struct Point {
	double x, y;

	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

	bool operator<(const Point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}

	Point operator+(const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}

	Point operator-(const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}

	double operator^(const Point &rhs) const {
		return x * rhs.y - y * rhs.x;
	}
    Point operator*(const double& rhs) const {
        return Point(x*rhs, y*rhs);
    }
} a[MN], p[MN];
Point generate(Point a, Point b, Point c) {
    uniform_real_distribution<double> dist(0, 1.0);
    std::mt19937 rng;
    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}());
    double u = dist(rng);
    uniform_real_distribution<double> dist2(0, u);
    std::mt19937 rng2;
    //Initialize with non-deterministic seeds
    rng2.seed(std::random_device{}());    
    double v = dist2(rng2);
    return (c*u+b*v+a*(1.0-u-v));
}
int n, tot;

void ConvexHull() {	//²úÉúÍ¹°ü
	sort(a + 1, a + 1 + n);
	tot = 0;
	for (int i = 1; i <= n; i++) {
		while (tot > 1 && ((p[tot - 1] - p[tot - 2]) ^ (a[i] - p[tot - 2])) <= 0.0)	tot--;
		p[tot++] = a[i];
	}
	int k = tot;
	for (int i = n - 1; i > 0; i--) {
		while (tot > k && ((p[tot - 1] - p[tot - 2]) ^ (a[i] - p[tot - 2])) <= 0.0)	tot--;
		p[tot++] = a[i];
	}
	if(n > 1)	tot--;
}
Point aa[3];
int s, ans = 0;
int main() {
	srand(time(NULL));
	for (int i = 0; i < 3; i++) cin >> aa[i].x >> aa[i].y;
    cin >> n;
    int init = 1000;
	int t = init;
    double ans = 0;
    while(t--) {
        for(int i = 1; i <= n; ++i) {
            a[i] = generate(aa[0], aa[1], aa[2]);
//            printf("%f %f\n")
        }
        ConvexHull();
        ans += (double)tot;
    }
    ans /= (double) init;
//	cout << ans << endl;
	printf("%.8f\n",ans);
//	cin >> s;
//	Point t;
//	for (int i = 1; i <= s; i++) {
//		cin >> t.x >> t.y;
//		if (Judge(t)) ans++;
//	}
//	printf("%d", ans);
	return 0;
}
