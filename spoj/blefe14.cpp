#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> A, B;
    int n, m, k, f, g = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &k);
        A.insert(k);
    }

    for (int i = 0; i < m && g; i++) {
        scanf(" %d", &k);
        if (A.find(k) == A.end()) {
            f = 0;
            for (set<int>::iterator it = B.begin(); it != B.end() && !f; ++it) {
                if (B.find(k - *it) != B.end()) f = 1;
            }
            if (!f) printf("%d\n", k), g = 0;
        }
        B.insert(k);
    }

    if (g) printf("sim\n");

}
