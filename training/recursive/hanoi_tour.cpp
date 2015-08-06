#include <cstdio>

int H(int n) {
    if (n == 1) return 1;
    return 2*H(n - 1) + 1;
}

int main() {
    printf("%d\n", H(2));
}
