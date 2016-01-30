#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main () {
    int n, s, c = 0;
    int v[MAX];
    scanf (" %d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf (" %d", &v[i]);
    sort (v, v+n);
    while (c < n) {
        int up = upper_bound (v+c+1, v+n, s-v[c]) - v;
        printf ("%d\n", up);
        c++;
    }
}
