#include <bits/stdc++.h>
#define MAX 300005
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int n, m;
pii v[MAX];

int main () {
    scanf ("%d %d", &n, &m);
    int a, s;
    priority_queue<int> d;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &s);
        v[i].ff = a, v[i].ss = s+a;
    }
    sort (v, v+n);
    d.push (-(v[0].ss+m));
    int cont = 1;
    for (int i = 1; i < n; i++) {
        int p = -d.top ();
        if (v[i].ff >= p-m && v[i].ff <= p) d.pop ();
        else cont++;
        d.push (-(v[i].ss+m));
    }
    printf ("%d\n", n-cont);
}
