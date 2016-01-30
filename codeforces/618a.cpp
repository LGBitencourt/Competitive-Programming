#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf (" %d", &n);
    for (int i = 20; i >= 0; i--)
        if ((1 << i) <= n)
            printf ("%d ", i + 1), n -= (1 << i);
    printf ("\n");
}
