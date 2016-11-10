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
    int n;
    scanf(" %d", &n);
    n -= 10;
    if (n <= 0) printf("0\n");
    else if (n == 10) printf("15\n");
    else if (n <= 11) printf("4\n");
    else printf("0\n");
}

