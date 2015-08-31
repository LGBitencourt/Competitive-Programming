#include <iostream>

using namespace std;

int a[100005];

int main() {
    int n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }
    for (int i = 1; i < n; i++) {
        if (a[0] != a[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
