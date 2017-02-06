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
    if (n % 2 == 0) {
        printf("%d\n", n / 2);
        for (int i = 0; i < n / 2; i++)
            printf("2%c", i == (n / 2) - 1 ? '\n' : ' ');
    } else {
        printf("%d\n", n / 2);
        for (int i = 1; i < n / 2; i++)
            printf("2 ");
        printf("3\n");
    }
}

