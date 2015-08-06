#include <cstdio>

bool search(int arr[], int init, int end, int target) {
    int mid = (init + end)/2;
    if (arr[mid] == target) return true;
    if (init == end) return false;
    if (arr[mid] < target) return search(arr, mid + 1, end, target);
    else return search(arr, init, mid, target);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d\n", search(arr, 0, 5, 1));
}
