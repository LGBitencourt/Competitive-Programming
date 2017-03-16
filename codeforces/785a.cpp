#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int get(string s) {
    if (s == "Tetrahedron") return 4;
    if (s == "Cube") return 6;
    if (s == "Octahedron") return 8;
    if (s == "Dodecahedron") return 12;
    if (s == "Icosahedron") return 20;
}

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        ans += get(a);
    }
    cout << ans << endl;
}

