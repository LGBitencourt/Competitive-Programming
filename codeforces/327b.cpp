#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int p) {
    for (int i = sqrt(p); i > 1; i--) {
        if (p % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i + (9999999-n) << " ";
    }
}
