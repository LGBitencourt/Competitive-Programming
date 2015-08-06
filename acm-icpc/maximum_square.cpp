#include <iostream>
#include <algorithm>

using namespace std;

int find_max(int M[1005][1005], int n, int m) {
    int S[1005][1005];
    int max = 0;
    for (int i = 0; i < m; i++) S[0][i] = M[0][i];
    for (int i = 0; i < n; i++) S[i][0] = M[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (M[i][j] == 1) {
                S[i][j] = min(S[i-1][j], min(S[i-1][j-1], S[i][j-1])) + 1;
                if (S[i][j] > max) max = S[i][j];
            }
            else S[i][j] = 0;
        }
    }
    return max;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    int M[1005][1005];

    cin >> n >> m;
    
    while (n != 0 && m != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
    
        cout << find_max(M, n, m) << '\n';
        cin >> n >> m;
    }
}
