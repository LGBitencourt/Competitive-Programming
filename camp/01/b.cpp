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

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAX = 1004;
const int modn = 1000000007;

int n, t, m;
int trop[MAX], acc[MAX];
bool seen[MAX];
vector<int> adj[MAX];

int main() {
    while (scanf ("%d %d", &n, &t)) {
        if (n == 0 && t == 0)
            break;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for (int i = 0; i < n; i++) 
            seen[i] = false, adj[i].clear ();
        int numCities = 0, numTrops = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &trop[i], &m);
            acc[i] = trop[i];
            for (int j = 0; j < m; j++) {
                int a;
                scanf ("%d", &a);
                adj[i].pb (a);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size (); j++) {
                int x = adj[i][j];
                acc[i] += trop[x];
            }
            pq.push (mp (acc[i], i));
        }
        while (!pq.empty ()) {
            pii x = pq.top ();
            if (seen[x.ss]) {
                pq.pop ();
            }
            else {
                seen[x.ss] = true;
                if (x.ff >= t) {
                    // se x for defensivel
                    numCities++;
                    numTrops += trop[x.ss];               
                } else {
                    for (int j = 0; j < adj[x.ss].size (); j++) {
                        int u = adj[x.ss][j];
                        acc[u] -= trop[x.ss];
                        pq.push (mp (acc[u], u));
                    }
                }
            }
        }
        printf ("%d %d\n", numCities, numTrops);
    }
}

