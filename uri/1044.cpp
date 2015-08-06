#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m > n) swap(n, m);
    if (n % m == 0) printf("Sao Multiplos\n");
    else printf("Nao sao Multiplos\n");
}
