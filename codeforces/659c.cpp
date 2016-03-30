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
const int MAX = 100005;
const int modn = 1000000007;

vector<int> has, buy;

int main () {
    int n, m, t;
    int tot, hm;
    tot = hm = 0;
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf (" %d", &t);
        has.pb(t);
    }
    sort (has.begin(), has.end());
    for (int i = 1; i <= 1000000; i++) {
        if (!binary_search (has.begin(), has.end(), i) && tot + i <= m)
            tot += i, hm++, buy.pb(i);
    }
    printf ("%d\n", hm);
    for (int i = 0; i < buy.size(); i++) {
        printf ("%d%c", buy[i], (i < buy.size() - 1) ? ' ' : '\n');
    }
}

