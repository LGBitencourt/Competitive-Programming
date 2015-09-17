#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m)
        cout << max(n, m) << endl;
}
