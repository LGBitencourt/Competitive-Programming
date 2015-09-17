#include <iostream>
#include <algorithm>

using namespace std;

int players[505];

int main() {
    int j, r, p, k;
    while (cin >> j >> r) {
        for (int i = 0; i < 505; i++) players[i] = 0;
        for (int i = 0; i < j*r; i++) {
            cin >> p;
            players[i % j] += p;
        }
        p = k = 0;
        for (int i = 0; i < j; i++)
            if (players[i] >= p) p = players[i], k = i;
        cout << k + 1 << endl;
    }
}
