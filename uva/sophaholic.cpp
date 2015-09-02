#include <iostream>
#include <algorithm>

using namespace std;

bool compare (int a, int b) { return a > b; }

int prices[50000];

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> prices[i];
        sort (prices, prices + n, compare);
        int d = 0;
        for (int i = 2; i < n; i += 3)
            d += prices[i];
        cout << d << '\n';
    }    
}
