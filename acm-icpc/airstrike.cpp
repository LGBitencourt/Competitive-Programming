#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 1005;
const int modn = 1000000007;
const double pi = 3.141;

pdd p[MAX];

int main() {
    int n, tc = 1, ans;
    double x1, x2, y1, y2, t, rmax;
    while (scanf (" %d", &n) && n != 0) {
        scanf (" %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &t);
        ans = n;
        rmax = t/pi;
        for (int i = 0; i < n; i++)
            scanf (" %lf %lf", &p[i].ff, &p[i].ss);
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            double dist_p1 = (p[i].ff - x1)*(p[i].ff - x1) + (p[i].ss - y1)*(p[i].ss - y1);
            if (dist_p1 > rmax) dist_p1 = rmax;
            double dist_p2 = rmax - dist_p1;
            for (int j = 0; j < n; j++) {
                double nd1 = (p[j].ff - x1)*(p[j].ff - x1) + (p[j].ss - y1)*(p[j].ss - y1);
                double nd2 = (p[j].ff - x2)*(p[j].ff - x2) + (p[j].ss - y2)*(p[j].ss - y2);
                if (nd1 > dist_p1 && nd2 > dist_p2) tmp++;
            }
            ans = min (tmp, ans);
        }
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            double dist_p2 = (p[i].ff - x2)*(p[i].ff - x2) + (p[i].ss - y2)*(p[i].ss - y2);
            if (dist_p2 > rmax) dist_p2 = rmax;
            double dist_p1 = rmax - dist_p2;
            for (int j = 0; j < n; j++) {
                double nd1 = (p[j].ff - x1)*(p[j].ff - x1) + (p[j].ss - y1)*(p[j].ss - y1);
                double nd2 = (p[j].ff - x2)*(p[j].ff - x2) + (p[j].ss - y2)*(p[j].ss - y2);
                if (nd1 > dist_p1 && nd2 > dist_p2) tmp++;
            }
            ans = min (tmp, ans);
        }
        printf ("%d. %d\n", tc++, ans);
    }
}

