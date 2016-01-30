#include <bits/stdc++.h>
#define MAX 40
using namespace std;

char str[MAX];
int l, r, hi, lo;

int main () {
    scanf (" %s", str);
    int n = strlen (str);
    int nivel = pow (2, n);
    l = lo = 0, r = hi = nivel-1;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '0') {
            r = (l+r+1)/2;
            hi = (lo+hi+1)/2;
        }
        else if (str[i] == '1') {
            l = (l+r+1)/2;
            hi = (lo+hi+1)/2;
        }
        else if (str[i] == '2') {
            r = (l+r+1)/2;
            lo = (lo+hi+1)/2;
        }
        else {
            l = (l+r+1)/2;
            lo = (lo+hi+1)/2;
        }
    }
    //printf ("l %d r %d lo %d hi %d\n", l, r, lo, hi);
    printf ("%d %d %d\n", n, l, lo);
}
