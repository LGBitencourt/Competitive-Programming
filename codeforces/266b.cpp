#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100;
const int modn = 1000000007;

char q[MAXN];

int main() {
    int n, t;
    scanf(" %d %d", &n, &t);
    scanf(" %s", q);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++)
            if (q[j] == 'B' && q[j + 1] == 'G')
                swap(q[j], q[j + 1]), j++;
    }
    printf("%s\n", q);
}

