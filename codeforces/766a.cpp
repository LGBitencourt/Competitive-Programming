#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

char a[MAXN], b[MAXN];

int main() {
    scanf(" %s %s", a, b);
    int la, lb;
    la = strlen(a), lb = strlen(b);
    if (strcmp(a, b) == 0) puts("-1");
    else printf("%d\n", max(la, lb));
}

