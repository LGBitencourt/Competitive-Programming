#include <bits/stdc++.h>
#define MAX 1000006
using namespace std;

char a[MAX], b[MAX];

int main () {
    int sa, sb, la, lb, i;
    sa = sb = i = 0;
    scanf (" %s %s", a, b);
    la = strlen (a), lb = strlen (b);
    while (a[sa] == '0' && sa < la) sa++;
    while (b[sb] == '0' && sb < lb) sb++;
    while (a[sa + i] == b[sb + i] && sa + i < la && sb + i < lb) i++;
    if (la - sa > lb - sb) printf (">\n");
    else if (lb - sb > la - sa) printf ("<\n");
    else if (a[sa + i] > b[sb + i]) printf (">\n");
    else if (b[sb + i] > a[sa + i]) printf ("<\n");
    else printf ("=\n");

}
