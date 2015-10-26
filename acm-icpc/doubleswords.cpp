#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

pair<int, int> it[100005];
int a[100005];

int main () {
    int t, n, total;
    scanf (" %d", &t);
    for (int z = 1; z <= t; z++) {
        set<int> s;
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            int y, k;
            scanf (" %d %d %d", &a[i], &y, &k);
            s.insert(a[i]), it[i] = make_pair(k, y);
        }
        total = s.size();
        for (int i = 0; i < n; i++) {
            set<int>::iterator j = s.lower_bound(it[i].second);
            if (j != s.end() && *j == a[i]) j++;
            if (j != s.end() && *j <= it[i].first) it[i] = it[n-1], a[i] = a[n-1], i--, n--;
        }
        sort (it, it + n);
        int l = -1;
        for (int i = 0; i < n; i++)
            if (it[i].second > l)
                total++, l = it[i].first;
        printf ("Case #%d: %d\n", z, total);
    }
}
