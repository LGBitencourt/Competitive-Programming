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
const int modn = 1000000007;

ll N, K, L;

matrix mul(matrix A, matrix B) {
    matrix C(K+1, vector<ll>(K+1));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000000;
    return C;
}



int main() {
    scanf (" %lld %lld %lld", &N, &K, &L);
    printf("%.06lld\n", f(N/5));
}

