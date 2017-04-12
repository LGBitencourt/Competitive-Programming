#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

class Point {
    public:
        Point() {}
        Point(int x, int y) : x(x), y(y) {}

        int x, y;

        int operator^ (const Point &o) const {
            return x * o.y - y * o.x;
        }

        Point operator- (const Point &o) const {
            return Point(x - o.x, y - o.y);
        }

        bool operator< (const Point &o) {
            return x != o.x ? x < o.x : y < o.y;
        }
};

int cross(const Point &a, const Point &b, const Point &c) {
    return (a - c) ^ (b - c);
}

vector<Point> convex_hull(vector<Point> &points) {
    int m, n;
    m = 0, n = (int) points.size();
    vector<Point> h(2 * n + 1);
    sort(points.begin(), points.end());

    for (int i = 0; i < n; i++) {
        while (m >= 2 && cross(h[m - 2], h[m - 1], points[i]) <= 0) m--;
        h[m++] = points[i];
    }

    for (int i = n - 2, t = m + 1; i >= 0; i--) {
        while (m >= t && cross(h[m - 2], h[m - 1], points[i]) <= 0) m--;
        h[m++] = points[i];
    }
    h.resize(m - 1);
    return h;
}

int ternary_search(int i, int j, int l, int r, const vector<Point> &h) {
    int x = (2*l + r) / 3, y = (2*r + l) / 3;
    if (r - l < 3) return cross(h[i], h[y % h.size()], h[j]);
    if (cross(h[i], h[x % h.size()], h[j]) > cross(h[i], h[y % h.size()], h[j]))
        return ternary_search(i, j, l, y, h);
    return ternary_search(i, j, x, r, h);
}

int main() {
    int tt;
    scanf(" %d", &tt);
    while (tt--) {
        int n, ans = 0;
        vector<Point> in, h;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf(" %d %d", &x, &y);
            in.push_back(Point(x, y));
        }
        h = convex_hull(in);
        for (int i = 0; i < (int) h.size(); i++)
            for (int j = i + 1; j < (int) h.size(); j++)
                ans = max(ans, ternary_search(i, j, i, j, h)
                        + ternary_search(j, i, j, i + (int) h.size(), h));
        printf("%d%s", ans / 2, ans % 2 ? ".5\n" : "\n");
    }
}

