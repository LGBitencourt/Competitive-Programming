#include <bits/stdc++.h>
using namespace std;

int main () {
    int x, ans;
    scanf (" %d", &x);
    ans = 0;
    for (int i = 5; i > 0; i--)
        ans += x/i, x = x%i;
    printf ("%d\n", ans);
}
