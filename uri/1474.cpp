#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > matrix;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 10005;
const int modn = 1000000;

ll N, K, L;
matrix I(3, vector<ll>(3));

matrix mul(matrix A, matrix B) {
    matrix C(3, vector<ll>(3));
    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++)
            for (int k = 1; k < 3; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % modn;
    return C;
}

matrix pow(matrix A, ll p) {
    if (p == 0) return I;
    if (p == 1) return A;
    if (p % 2) return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main() {
    scanf (" %lld %lld %lld", &N, &K, &L);
    K %= modn, L %= modn;
    I[1][1] = 1, I[1][2] = 0;
    I[2][1] = 0, I[2][2] = 1;
    vector<ll> f(3);
    f[1] = K;
    f[2] = (K*K % modn) + L % modn;
    matrix T(3, vector<ll>(3));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = K, T[2][2] = L;
    T = pow(T, N/5 - 1);
    ll ans = 0;
    for (int i = 1; i < 3; i++)
        ans = (ans + T[1][i] * f[i]) % modn;
    printf("%.06lld\n", ans);
}

