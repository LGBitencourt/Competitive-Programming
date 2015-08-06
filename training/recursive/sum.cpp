#include <cstdio>

int sum(int arr[], int n) {
    n--;
    if (n < 0) return 0;
    return arr[n] > 0 ? arr[n] + sum(arr, n) : sum(arr, n);
}

int main() {
    int arr[3] = {-1, 2, 3};
    printf("%d\n", sum(arr, 3));
}
