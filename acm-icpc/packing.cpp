#include <cstdio>

int main() {
    int t, l, w, h, bl, bw, bh;

    h = l = w = 20;

    scanf(" %d", &t);
    for (int i = 1; i <= t; i++) {
        scanf(" %d %d %d", &bl, &bw, &bh);
        if (bl > l || bl > w || bl > h || bh > h || bh > w || bh > l || bw > w || bw > h || bw > l) printf ("Case %d: bad\n", i);
        else printf ("Case %d: good\n", i);
    }
}
