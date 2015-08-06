#include <cstdio>

#define MAX 100000

long long int bsearch(long long int vet[], int end, long long int target) {
    int i = 0, center;
    end--;

    if (vet[0] == target) return 0;

    while (i <= end) {
        center = (i + end)/2;
        if (target == vet[center]) {
            if (vet[(center - 1)] < target) {
                return center;
            } else {
                end = center - 1;
            }
        } else if (target < vet[center]) {
            end = center - 1;
        } else {
            i = center + 1;
        }
    }
    return -1;
}

int main() {
    int n, q;
    long long int vet[MAX];
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        long long int tmp;
        scanf("%lld", &tmp);
        vet[i] = tmp;
    }
    for (int i = 0; i < q; i++) {
        long long int tmp;
        scanf("%lld", &tmp);
        printf("%lld\n", bsearch(vet, n, tmp));
    }
    return 0;
}
