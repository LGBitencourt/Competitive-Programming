#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

double n, k;
double sum;

int main() {
    scanf(" %lf %lf", &n, &k);
    for (int i = 0; i < n; i++) {
        double a;
        scanf(" %lf", &a);
        sum += a;
    }

    int i = 0;
    while (round(sum / (n + i)) < k) sum += k, i++;
    printf("%d\n", i);
}

