#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int n, m, vl, vc, u, d, l, r;

bool valid(int i, int j) {
    printf("Vetor: (%d, %d)\n", vl, vc);
    printf("u %d d %d l %d r %d\n", u, d, l, r);
    if (i + vl < 1 || i + vl > n) return false;
    puts("a");
    if (j + vc < 1 || j + vc > m) return false;
    puts("b");
    if (i - u < 1 || i + d > n) return false;
    puts("c");
    if (j - l < 1 || j + r > m) return false;
    puts("d");
    return true;
}

pii get(int i, int j) {
    return pii(i + vl, j + vc);
}

bool next_move() {
    char c, step[10];
    scanf(" %s", step);
    if (strlen(step) > 1) return false;
    c = step[0];
    if (c == 'U') {
        vl--;
        u = min(
    } else if (c == 'D')
        vl++, d++;
    else if (c == 'L')
        vc--, l++;
    else if (c == 'R')
        vc++, r++;
    return true;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            printf("Tentando (%d, %d)\n", i, j);
            if (valid(i, j)) {
                int x, y;
                tie(x, y) = get(i, j);
                printf("%d %d\n", x, y);
                fflush(stdout);
                if (!next_move()) return 0;
            }
        }
}

