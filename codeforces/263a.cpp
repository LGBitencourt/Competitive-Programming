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
    int x, y;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            int a;
            scanf(" %d", &a);
            if (a) x = i, y = j;
        }
    printf("%d\n", abs(x - 2) + abs(y - 2));
}

