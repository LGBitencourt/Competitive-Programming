#include <iostream>
#include <cmath>

#define lli long long int

using namespace std;

int main() {
    lli n, b;
    while (cin >> n >> b) {
        if (n <= (1ll << b+1) - 1) cout << "yes\n";
        else cout << "no\n";
    }
}
