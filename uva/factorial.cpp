#include <iostream>
#include <algorithm>

using namespace std;

int f[100000];

void fat() {
    f[0] = 1;
    for (int i = 1; f[i - 1] <= 100000; i++)
        f[i] = i * f[i - 1];
        
}

int main() {
    fat();
    int n;
    while (cin >> n) {
        int sum = 0, k = 0;
        for (int i = 8; i >= 0; i--)
            if (sum + f[i] <= n) sum += f[i], k++, i++;
        cout << k << endl;
    }
}
