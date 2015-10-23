#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main () {
    int n;
    pair<int, int> p[1000005];
    while (scanf (" %d", &n) != EOF) {
        int t = n;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf (" %d %d", &x, &y);
            p[i] = make_pair(y, x);
        }
        sort (p, p+n);
        int last = p[0].first;
        for (int i = 1; i < n; i++) {
            if (p[i].second <= last)
                t--;
            else last = p[i].first;
        }
        printf ("%d\n", t);
    }
}
