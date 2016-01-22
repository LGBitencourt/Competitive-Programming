#include <bits/stdc++.h>
using namespace std;

char c[100005];

int main () {
    int n = 0, um = 0, mln = 0, ln = 0, p = -1;
    while (scanf (" %c", &c[n]) != EOF) {
        if (c[n] == '1') um++;
        n++;
    }
    for (int i = 0; i < n; i++) {
        if (c[i] == '0') ln++;
        else ln = 0;
        if (ln >= mln) mln = ln, p = i;
    }
    c[0] = '0';
    int cd = n - p - 1;
    for (int i = 0; i < p; i++)
        if (c[i] == '1') ln = i;
    cd += ln;
    for (int i = 0; i < n; i++)
        if (c[i] == '1') p = i;
    printf ("%d\n", 4*um + 7*(min(p, cd)));
}
