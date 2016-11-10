#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

char a[MAXN], b[MAXN];

int main() {
    scanf(" %s", a);
    scanf(" %s", b);
    for (int i = 0; a[i] != 0; i++) {
        if (isupper(a[i])) a[i] = tolower(a[i]);
        if (isupper(b[i])) b[i] = tolower(b[i]);
    }
    int ans = strcmp(a, b);
    printf("%d\n", ans / abs(ans != 0 ? ans : 1));
}

