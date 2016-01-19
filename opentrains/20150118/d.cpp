#include <bits/stdc++.h>
using namespace std;

int main () {
    double z, h1, h2, t1, t2, ans;
    scanf (" %lf %lf %lf %lf", &h1, &t1, &h2, &t2);
    z = h1/h2;
    //ans = (2*t2*z - 2*t1) + sqrt ((-2*t2*z+2*t1)*(-2*t2*z+2*t1) - 4*(z-1)*(t2*t2*z - t1*t1));*/
    //printf ("%lf\n", ans/(2*(z-1)));
    z = sqrt(z);
    ans = (t1 - t2*z)/(1-z);
    printf ("%lf\n", ans);
}
