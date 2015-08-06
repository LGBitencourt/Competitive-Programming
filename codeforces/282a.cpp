#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, x = 0;
    string o;

    cin >> n;

    while (n--) {
        cin >> o;
        if (o[1] == '+') x++;
        else x--;
    }

    cout << x << "\n";
}
