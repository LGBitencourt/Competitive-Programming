#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    string s, aux;
    int m, l, r, k, n;
    cin >> s >> m;
    while (m--) {
        aux = s;
        cin >> l >> r >> k;
        l--, r--;
        n = r - l + 1;
        for (int i = 0; i < n; i++)
            aux[l + ((k+i)%n)] = s[l + i];
        s = aux;
    }
    cout << s << endl;
}
