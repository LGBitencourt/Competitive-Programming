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

int main() {
    bool ans = false;
    char c;
    while (scanf(" %c", &c) != EOF)
        if (c == 'H' || c == 'Q' || c == '9') ans = true;
    if (ans) puts("YES");
    else puts("NO");
}

