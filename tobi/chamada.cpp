#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string names[105];

int main() {
    ios::sync_with_stdio(false);
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> names[i];

    sort(names, names + n);

    cout << names[k-1] << '\n';
}
