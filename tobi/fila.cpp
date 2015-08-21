#include <cstdio>
#include <map>

using namespace std;

int removed[100005];
int fila[100005];

int main() {
    int n, m, tmp;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &fila[i]);
    scanf(" %d", &m);
    while (m--) {
        scanf(" %d", &tmp);
        removed[tmp] = 1;
    }
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (!removed[fila[i]]) {
            if (!f) printf(" ");
            f = false;
            printf("%d", fila[i]);
        }
    }
    printf("\n");
}
