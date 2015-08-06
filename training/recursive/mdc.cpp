#include <iostream>

using namespace std;

int mdc(int n, int m) {
    if (n % m == 0) return m;
    return mdc(m, n % m);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << mdc(n, m) << endl;
}
