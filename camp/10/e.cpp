#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > matrix;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int t;

matrix mul(matrix A, matrix B) {
    matrix C(3, vector<ll>(3));
    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++)
            for (int k = 1; k < 3; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % modn;
    return C;
}

matrix pow (matrix A, ll p) {
    if (p == 1LL) return A;
    if (p % 2) return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main() {
    scanf (" %d", &t);
    while (t--) {
        ll n;
        scanf (" %lld", &n);
        matrix F(3, vector<ll>(3));
        F[1][1] = 0, F[1][2] = 1;
        F[2][1] = 1, F[2][2] = 1;
        F = pow(F, n);
        printf("%lld\n", F[1][2]);
    }
}

