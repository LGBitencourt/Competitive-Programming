#include <iostream>
#include <algorithm>

#define MAX 100005

using namespace std;

int n;
int m[MAX], v[MAX];

void ma() {
    m[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        m[i] = max(m[i + 1], v[i + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ma();
    int f = 1;
    for (int i = 0; i < n; i++) {
        if (!f) cout << ' ';
        f = 0;
        if (m[i] < v[i]) cout << 0;
        else cout << m[i] - v[i] + 1;
    }
    cout << '\n';
}
