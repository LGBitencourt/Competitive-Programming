#include <bits/stdc++.h>

int sx, sy, sz;

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int x, y, z;
        scanf(" %d %d %d", &x, &y, &z);
        sx += x, sy += y, sz += z;
    }
    printf("%s\n", (sx == 0 && sy == 0 && sz == 0) ? "YES" : "NO");
}

