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
const int MAX = 105;
const int modn = 1000000007;

int degree[30];
vector<int> adj[30];

int main() {
    int n;
    char s[105][30];
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %s", s[i]);
    int k, l;
    for (int i = 1; i < n; i++) {
        k = strlen (s[i]), l = strlen (s[i-1]);

    }
    return 0;
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (degree[i] == 0) q.push(i);

    vector<int> tp;
    while (!q.empty()) {
        int v = q.front();
        tp.pb(v);
        q.pop();
        for (int u : adj[v]) {
            degree[u]--;
            if (degree[u] == 0) q.push(u);
        }
    }

    bool c = false;
    for (int i = 0; i < 26; i++)
        if (degree[i] != 0) c = true;
    if (c) printf ("Impossible\n");
    else { for (int t : tp) printf ("%c", t + 'a'); putchar ('\n'); }
}

