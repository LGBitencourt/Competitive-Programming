#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

char s[MAXN];

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        scanf(" %s", s);
        int l = strlen(s);
        if (l <= 10) printf("%s\n", s);
        else printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
    }
}

