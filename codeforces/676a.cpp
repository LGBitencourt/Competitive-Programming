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
const int MAX = 104;
const int modn = 1000000007;

int main() {
    int n, pmi, pma;
    int a;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %d", &a);
        if (a == 1) pmi = i;
        if (a == n) pma = i;
    }
    if (pmi > pma) swap(pmi, pma);

    printf("%d\n", max(0, max(pma, n-pmi-1)));
}

