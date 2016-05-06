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
const int MAX = 200004;
const int modn = 1000000007;

int movie[2][MAX];
int n, m;
map<int, int> c;

int main () {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf (" %d", &a);
        if (c.find(a) == c.end()) c[a] = 1;
        else c[a]++;
    }
    scanf (" %d", &m);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < m; j++) {
            scanf (" %d", &movie[i][j]);
        }
    int ans = 0;
    for (int i = 1; i < m; i++) {
        if (c[movie[0][i]] > c[movie[0][ans]] || (c[movie[0][i]] == c[movie[0][ans]] && 
                    c[movie[1][i]] > c[movie[1][ans]]))
                ans = i;
    }
    printf ("%d\n", ++ans);
}
