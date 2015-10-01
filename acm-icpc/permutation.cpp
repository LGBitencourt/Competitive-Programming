#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int n;
    int a[505], v[505];
    while (cin >> n, n != 0) {
        memset(a, -1, sizeof a);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = n; i > 0; i--) {
            if (a[v[i - 1]] != -1) {
                for (int j = n - i; j > v[i - 1]; j--)
                    a[j] = a[j - 1];
            }
            a[v[i - 1]] = i;
        }
        cout << a[0];
        for (int i = 1; i < n; i++)
            cout << ',' << a[i];
        cout << '\n';
    }
}
