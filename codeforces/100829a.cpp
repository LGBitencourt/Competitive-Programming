#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<double, double> pdd;

const double eps = 1e-9;
const double inf = 1e20;
const int MAXN = 112345;

int n;
pdd c[MAXN];

double f(double t) {
    double mi = inf, ma = 0;
    for (int i = 0; i < n; i++) {
        double d = c[i].ss * (t - c[i].ff);
        mi = min(mi, d);
        ma = max(ma, d);
    }
    return ma - mi;
}

double ternary_search(double l, double r, int k) {
    if (k >= 100) return f((r + l) / 2);

    double lt = (2 * l + r) / 3;
    double rt = (l + 2 * r) / 3;

    if (f(lt) > f(rt)) return ternary_search(lt, r, k + 1);
    return ternary_search(l, rt, k + 1);
}

int main() {
    while (scanf(" %d", &n), n != 0) {
        double t = 0;
        for (int i = 0; i < n; i++) {
            double tk, vk;
            scanf(" %lf %lf", &tk, &vk);
            t = max(t, tk);
            c[i] = pdd(tk, vk);
        }
        printf("%f\n", ternary_search(t, 1e10, 0));
    }
}

