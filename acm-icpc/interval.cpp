#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int bit[100005][2];
int V[100005];

int q(int idx) {
    int p = 0;
    for (int i = idx; i > 0; i -= i&-i)
        p += bit[i][0];
    return p;
}

int qz(int idx) {
    int p = 0;
    for (int i = idx; i > 0; i -= i&-i)
        p += bit[i][1];
    return p;
}

void u(int idx, int x) {
    for (int i = idx; i <= N; i += i&-i)
        bit[i][0] += x;
}

void uz(int idx, int x) {
    for (int i = idx; i <= N; i+= i&-i)
        bit[i][1] += x;
}

int main () {
    ios::sync_with_stdio(false);
    while (cin >> N >> K) {
        for (int i = 0; i <= N; i++) bit[i][0] = bit[i][1] = 0;
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            V[i] = x;
            if (x == 0) uz(i, 1);
            else if (x < 0) u(i, 1);
        }
        for (int i = 0; i < K; i++) {
            char c;
            int idx, jdx;
            cin >> c >> idx >> jdx;
            if (c == 'C') {
                if (V[idx] < 0) {
                    u(idx, -1);
                } else if (V[idx] == 0) {
                    uz(idx, -1);
                }
                if (jdx < 0) u(idx, 1);
                else if (jdx == 0) uz(idx, 1);
                V[idx] = jdx;
            } else {
                int r = q(jdx) - q(idx - 1);
                int rz = qz(jdx) - qz(idx - 1);
                if (rz > 0) cout << '0';
                else if (r % 2 == 0) cout << '+';
                else cout << '-';
            }
        }
        cout << '\n';
    }
}
