#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, s, t;
    float a;
    scanf ("%d %d %d", &n, &t, &s);
    for (int i = 0; i < n; i++) {
        scanf ("%f",&a);
        a = (float) ((a + t + s)/2);
        printf ("%f\n", a);
    }
}
