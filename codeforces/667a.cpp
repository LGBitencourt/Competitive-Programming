#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 10004;
const int modn = 1000000007;
const double pi = acos (-1);

int main() {
    double d, h, v, e, vol, area, dc, ic;
    scanf (" %lf %lf %lf %lf", &d, &h, &v, &e);
    vol = pi*(d/2)*(d/2)*h;
    ic = pi*(d/2)*(d/2)*e;
    if (v - ic < eps) {
        printf ("NO\n");
    } else {
        printf ("YES\n");
        printf ("%lf\n", vol/(v - ic));
    }
}

