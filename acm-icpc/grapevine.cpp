#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int B[1005][505], M[505][505];
int d = 0;

void fill(int n, int m) {
    d = 0;

    for (int k = n - 1; k >= 0; k--) {
        int i = k, j = 0, t = 1;
        while (i < n && j < m) B[d][t++] = M[i++][j++];
        B[d++][0] = t - 1;
    }

    for (int k = 1; k < m; k++) {
        int i = 0, j = k, t = 1;
        while (i < n && j < m) B[d][t++] = M[i++][j++];
        B[d++][0] = t - 1;
    }

}

int main() {
    ios::sync_with_stdio(false);

    int n, m, q, l, r;
    while (cin >> n >> m, n != 0 && m != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];

        fill(n, m);
        cin >> q;

        while (q--) {
            cin >> l >> r;

            int x = 0;
            for (int i = 0; i < d; i++) {
                int *itl, *itr;
                itl = lower_bound(B[i] + 1, B[i] + B[i][0] + 1, l);
                itr = upper_bound(B[i] + 1, B[i] + B[i][0] + 1, r);

                int c = itr - itl;
                if (c > x) x = c;

            }
            cout << x << '\n';
        }
        cout << "-\n";

        /*for (int i = 0; i < d; i++) {
            for (int j = 0; j < B[i][0]; j++) {
                cout << B[i][j] << ' ';
            }
            cout << '\n';
        }*/
    }
}
