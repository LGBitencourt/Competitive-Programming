#include <bits/stdc++.h>
#define ff x
#define ss y
#define MAX 100005
using namespace std;
typedef long long ll;

struct P {
    ll i, x, y;
} p[MAX];

bool compare (P a, P b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool linear (P p1, P p2, P p3) {
    if (p1.ff*p2.ss + p3.ff*p1.ss + p2.ff*p3.ss - p3.ff*p2.ss - p2.ff*p1.ss - p1.ff*p3.ss != 0)
        return false;
    return true;
}

int main () {
    ios::sync_with_stdio (false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].i = i+1;
    }
    sort (p, p + n, compare);
    for (int i = 0; i < n-2; i++) {
        if (!linear (p[i], p[i+1], p[i+2])) {
            cout << p[i].i << " " << p[i+1].i << " " << p[i+2].i << endl;
            return 0;
        }
    }
}
