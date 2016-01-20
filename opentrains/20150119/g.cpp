#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, pair<int, int> > pii;
typedef long long ll;

set<pii> s;
int X[6] = { 1, -1, 0, 0, 0, 0 };
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 0, 0, 0, 0, 1, -1 };

int main () {
    ll a, b, c;
    int n, x, y, z;
    scanf ("%lld %lld %lld %d", &a, &b, &c, &n);
    ll area = 2*a*b + 2*a*c + 2*b*c;
    set<pii> s;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &x, &y, &z);
        s.insert (make_pair (x, make_pair (y, z)));
    }
    set<pii> ::iterator it;
    ll cont = 0;
    for (it = s.begin (); it != s.end (); it++) {
        for (int i = 0; i < 6; i++) {
            int xx = (*it).ff + X[i], yy = (*it).ss.ff+ Y[i], zz = (*it).ss.ss + Z[i];
            if (xx < 0 || xx > a || yy < 0 || yy > b || zz < 0 || zz > c)
                cont--;
            else if (s.find (make_pair (xx, make_pair (yy, zz))) == s.end ())
                cont++;
        }
    }
    area += cont;
    printf ("%lld\n", area);
}
