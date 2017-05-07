#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

vector<int> v[MAXN];

int sum_digits(int t) {
    int s = 0;
    while (t > 0) {
        s += (t % 10);
        t /= 10;
    }
    return s;
}

int find(int s, int n) {
    int i = 0, j = v[s].size() - 1;
    while (i < j) {
        int m = (i + j + 1) / 2;
        if (v[s][m] <= n) i = m;
        else j = m - 1;
    }
    return v[s][i];
}

int main() {
    int n;
    for (int i = 0; i < 100005; i++) {
        int t = sum_digits(i);
        v[t].push_back(i);
    }
    char x[100];
    while (scanf(" %s", &x)) {
        if (x[0] == 'E') return 0;
        n = atoi(x);
        int s = sum_digits(n);
        s--;
        printf("%d\n", find(s, n));
    }
}

