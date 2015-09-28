#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << ' ' << (max(a, b) - min(a, b))/2 << '\n';
}
