#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 105

using namespace std;

int pp[MAX][MAX], mpd[MAX][MAX];
int n;

int pd (int i, int j) {
    if (mpd[i][j] != -1) return mpd[i][j];
    if (i == j) return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min(ans, pp[i][k]*pp[k+1][j] + pd(i, k) + pd(k + 1, j));
    }
    mpd[i][j] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> n) {
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                mpd[i][j] = -1;
        for (int i = 0; i < n; i++)
            cin >> pp[i][i];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += pp[k][k];
                pp[i][j] = sum % 100;
            }
        }
        cout << pd(0, n-1) << '\n';
    }
}

