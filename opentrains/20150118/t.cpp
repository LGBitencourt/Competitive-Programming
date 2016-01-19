#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int accIn = 0, accCon = 180;
int k = 0, n;
bool f = false;
pii v[2000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &v[i].ff, &v[i].ss);
    }
    sort (v, v+n);
    int k = 0;
    for (int i = 1; i <= 1826; i++) {
        if (i >= v[k].ff && i <= v[k].ss) {
            accIn++;
            if (!f) accCon = 180, f = true;
            if (i == v[k].ss) k++;
        }
        if (f) {
            accCon--;
            if (accIn > 90) {
                printf ("No\n");
                return 0;
            }
            if (accCon == 0) accIn = 0, f = false;
        }
    }
    printf ("Yes\n");
}
