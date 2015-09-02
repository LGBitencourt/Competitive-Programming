#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int m[5] = {1, 5, 10, 25, 50};
long long int mdp[5][30005];

long long int dp(int i, int v) {
    if (v == 0) return 1;
    if (i == 5 || v < 0) return 0;
    if (mdp[i][v] != -1) return mdp[i][v];
    mdp[i][v] = dp(i + 1, v) + dp(i, v - m[i]);
    return mdp[i][v];
}

int main() {
    ios::sync_with_stdio(false);
    int v;
    memset(mdp, -1, sizeof(mdp));
    while (cin >> v) {
        long long int w = dp(0, v);
        if (w == 1)
            cout << "There is only 1 way to produce " << v << " cents change.\n";
        else
            cout << "There are " << w << " ways to produce " << v << " cents change.\n";
    }
}
