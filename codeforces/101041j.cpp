#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 20;
const int modn = 1000000007;

int dist[MAXN][MAXN];


int dp (int v, int mask) {
    if (__builtin_popcount(mask) == M && v == D) return 0;
    if (mdp[v][mask] != -1) return mdp[v][mask];
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (((1 << i) & mask) == 0)

}

int main() {
}

