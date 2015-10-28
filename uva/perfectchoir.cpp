#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
    int n;
    while (scanf (" %d", &n) != EOF) {
        int b = 1;
        int c[10005];
        for (int i = 0; i < n; i++)
            scanf (" %d", &c[i]);
        printf ("%d\n", b);
    }
}
