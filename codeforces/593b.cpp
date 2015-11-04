#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<double, double> pdd;

int main () {
    int n;
    bool ans = false;
    pdd p[100005];
    double x, y;
    scanf ("%d %lf %lf", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        double a, b;
        scanf (" %lf %lf", &a, &b);
        p[i].first = a*x + b, p[i].second = a*y + b;
    }
    sort (p, p + n);
    for (int i = 1; i < n; i++)
        if (p[i].second < p[i-1].second && p[i].first != p[i-1].first)
            ans = true;
    printf ("%s\n", ans ? "YES" : "NO");
}
