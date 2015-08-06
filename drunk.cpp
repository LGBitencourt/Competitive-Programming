#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, n, escaped;
    cin >> t;

    while (t--) {
        cin >> n;
        //true == locked
        bool cells[105] = {true};
        escaped = 0;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i % j == 0) {
                    if (cells[i]) cells[i] = false;
                    else cells[i] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++) escaped += cells[i];
        cout << escaped << '\n';
    }

}
