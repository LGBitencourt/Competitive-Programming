#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 3005;

int n;
ll b[MAX];

int solve (int i, ll a) {
    if (i >= n) return 0;
    ll sum = 0;
    while (sum < a && i < n) {
        sum += b[i];
        i++;
    }
    if (i >= n && sum < a) return 0;
    return 1 + solve (i, sum);
}

int main () {
    while (scanf (" %d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf (" %lld", b+i);
        printf ("%d\n", 1 + solve (1, b[0]));
    }
}

