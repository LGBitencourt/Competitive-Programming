#include <bits/stdc++.h>
using namespace std;

int main () {
    double z, h1, h2, t1, t2, ans;
    scanf (" %lf %lf %lf %lf", &h1, &t1, &h2, &t2);
    z = h1/h2;
    z = sqrt(z);
    ans = (t1 - t2*z)/(1-z);
    printf ("%lf\n", ans);
}
