#include <bits/stdc++.h>
using namespace std;

int main () {
    int p, d, t, c;
    bool can = true;
    scanf (" %d %d", &p, &d);
    t = d;
    while (p--) {
        scanf (" %d", &c);
        if (c > t) can = false;
        t = c + d;
    }
    if (42195 - t > d) can = false;
    if (can) printf ("S\n");
    else printf ("N\n");
}
