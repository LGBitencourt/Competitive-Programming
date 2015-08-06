#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int chrono[105];
int t = 0;

struct car {
    int index, sensor;
};

car cars[105];

bool compare(car a, car b) {
    if (a.sensor != b.sensor && chrono[a.index] != 0 && chrono[b.index] != 0) return a.sensor > b.sensor;
    if (chrono[a.index] != 0 && chrono[b.index] != 0)
        return chrono[a.index] < chrono[b.index];
    if (chrono[a.index] == 0 || chrono[b.index] == 0)
        return chrono[a.index] > chrono[b.index];
}

int main() {
    ios::sync_with_stdio(false);

    int k, m, n, c, p;
    bool f = true;

    cin >> k >> n >> m;

    for (int i = 1; i <= n; i++) {
        car x;
        x.index = i;
        x.sensor = 0;
        cars[i] = x;
    }

    while (m--) {
        cin >> c >> p;

        if (chrono[c] == 0) {
            if (p == 1)
                cars[c].sensor = 1;
            chrono[c] = ++t;
        } else {
            if (cars[c].sensor % k == p - 1) cars[c].sensor += 1, chrono[c] = ++t;
        }
    }

    sort(cars + 1, cars + n + 1, compare);

    for (int i = 1; i <= n; i++) {
        if (!f) cout << ' ';
        cout << cars[i].index;
        f = false;
    }
    cout << '\n';
}
