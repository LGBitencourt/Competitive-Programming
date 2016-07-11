#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int n;
ll cont;
int v[MAXN];
string s;

void merge (int l, int m, int r) {
    int i, j;
    i = l, j = m;
    int aux[r-l+1], k = 0;
    while (i < m && j < r) {
        if (v[i] < v[j]) {
            aux[k++] = v[i++];
        } else {
            cont += (ll) m-i;
            aux[k++] = v[j++];
        }
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    for (int i = 0; i < k; i++) 
        v[i+l] = aux[i];
}

void mergesort (int l, int r) {
    if (l < r-1) {
        int m = (l+r)/2;
        mergesort (l, m);
        mergesort (m, r);
        merge (l, m, r);
    } 
    return;
}

int main() {
    while (scanf ("%d", &n) && n != 0) {
        cont = 0;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            cin >> s; 
            m[s] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            v[i] = m[s];
        }
        mergesort (0, n);
        printf ("%lld\n", cont);
    }
}

