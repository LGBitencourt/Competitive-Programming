#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int main() {
    int k, a, b, ans;
    scanf(" %d %d %d", &k, &a, &b);
    if (a < b) swap(a, b);
    if (a % k > 0 && b < k) ans = -1;
    else ans = a / k + b / k;
    printf("%d\n", ans);
}

