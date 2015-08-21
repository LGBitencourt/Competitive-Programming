#include <cstdio>
#include <algorithm>

using namespace std;

int v[5] = {1, 2, 5, 3, 4};

int vmax(int n) {
    if (n == 1)
        return v[0];
    return max (v[n-1], vmax(n - 1));
}

int main() {
    printf("%d\n", vmax(5));
}
