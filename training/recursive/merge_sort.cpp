#include <iostream>

#define MAXN 1001

using namespace std;

int input[MAXN], aux[MAXN];

void merge_sort(int init, int end) {
    if (init == end) return;

    merge_sort(init, (init + end)/2);
    merge_sort(((init + end)/2) + 1, end);

    int size = 0, j = ((init + end)/2) + 1;

    for (int i = init; i <= (init + end)/2; i++) {
        while (j <= end && input[j] < input[i]) aux[size++] = input[j++];

        aux[size++] = input[i];
    }

    while (j <= end) {
        aux[size++] = input[j++];
    }

    for (int i = init; i <= end; i++) input[i] = aux[i - init];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> input[i];

    merge_sort(1, n);

    for (int i = 1; i <= n; i++) cout << input[i] << " ";
    cout << endl;
}
