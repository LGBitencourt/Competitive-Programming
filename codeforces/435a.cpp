#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, b = 1, c;
    queue<int> q;
    cin >> n >> m;
    c = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (c + a <= m)
            c += a;
        else c = a, b += 1;
    }
    cout << b << '\n';
}
