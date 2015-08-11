#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, C;
int memo[50][50];
int W[50], V[50];

int backpack (int i, int weight) {
    if (i == n) return 0;
    if (memo[i][weight]) return memo[i][weight];

    int ans, r1, r2;
    r1 = r2 = INT_MAX;

    if (W[i] <= weight)
        r1 = V[i] + backpack(i + 1, weight - W[i]);
    r2 = backpack(i + 1, weight);

    ans = max(r1, r2);
    memo[i][weight] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> C >> n;
    for (int i = 0; i < n; i++)
        cin >> W[i] >> V[i];

    cout << backpack(0, C) << '\n';
}
