#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAX = 3005;

int n;
ll acc[MAX], v[MAX], me[MAX][MAX];

int bs (int i, int ant) {
    int l = i, h = n, m;
    while (l < h) {
        m = (l+h)/2;
        if (acc[m]-acc[i-1] >= ant) {
            h = m;
        } else {
            l = m+1;
        }
    }
    return h;
}

ll dp (int j, int i) {
    if (i == n+1) {
        return 0;
    }
    if (me[j][i] != -1) return me[j][i];
    ll ans = -1, sum = 0, ant;
    ant = acc[i-1] - acc[j-1];
    int ind = bs (i, ant);
    for (int l = ind; l <= n; l++) {
        sum += acc[l] - acc[i-1];
        if (sum >= ant)
            ans = max (ans, 1 + dp (i, l+1));
    }
    return me[j][i] = ans;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        memset (me, -1, sizeof me);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &v[i]);
        }
        acc[0] = 0;
        for (int i = 1; i <= n; i++) {
            acc[i] = acc[i-1] + v[i];
        }

        printf ("%lld\n", dp (0, 1));
    }
}

