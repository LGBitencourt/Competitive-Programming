#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k, l, r;
    int u[100005] = {0};

    cin >> n >> k;

    l = 0, r = n - 1;

    for (int i = 0; i < k; i++) {
        u[(i & 1) == 0 ? l : r] = 1;
        if ((i & 1) == 0)
            cout << ((1 + (l++)));
        else
            cout << ((1 + (r--)));
        cout << ' ';
    }

    if ((k & 1) == 1) {
        for (int i = 0; i < n; ++i) {
            if (!u[i]) cout << i + 1 << ' ';
        }
    } else {
        for (int i = n - 1; i >= 0; --i) {
            if (!u[i]) cout << i + 1 << ' ';
        }
    }

}
