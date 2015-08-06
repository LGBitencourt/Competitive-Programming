#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, p, g;
    int grid[1005];
    
    cin >> n;

    while (n != 0) {
        for (int i = 0; i <= n; i++) grid[i] = -1;
        bool v = true;
        for (int i = 0; i < n; i++) {
            cin >> p >> g;

            if (i + g < n && i + g >= 0 && grid[i + g] == -1) grid[i + g] = p;
            else v = false;
        }

        if (v) {
            int f = 1;
            for (int i = 0; i < n; i++) {
                if (!f) cout << ' ';
                cout << grid[i];
                f = 0;
            }
            cout << '\n';
        } else cout << -1 << '\n';

        cin >> n;
    }
}
