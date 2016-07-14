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
const int MAXN = 105;
const int modn = 1000000007;

int r;
int p[MAXN], q[MAXN];
int pot[MAXN][MAXN];
bool seenP[MAXN], seenQ[MAXN];

int fexp (int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (pot[x][y] != -1) return pot[x][y];
    if (y % 2 == 0) return pot[x][y] = (fexp (x/2, y*y % r)) % r; 
    return pot[x][y] = (x * fexp (x/2, y*y % r)) % r;
}

int main() {
    int numP, numQ;
    scanf ("%d", &r);
    scanf ("%d", &numP);
    for (int i = 0; i <= numP; i++) 
        scanf ("%d", &p[i]);
    scanf ("%d", &numQ);
    for (int i = 0; i <= numQ; i++) 
        scanf ("%d", &q[i]);
   
    memset (pot, -1, sizeof pot); 
    for (int x = 0; x < r; x++) {
        pot[x][0] = 1;
        for (int exp = 1; exp <= max (numQ, numP); exp++) 
            pot[x][exp] = fexp (x, exp);
    }

    int ans = 1;
    for (int x = 0; x < r; x++) {
        int atual = x;
        set<int> setP;
        while (!seenP[atual]) {
            seenP[atual] = true;
            int val = 0;
            for (int i = 0; i <= numP; i++) 
                val += (p[i] * pot[atual][numP-i]) % r;
            printf ("val %d\n", val);
            if (seenP[val]) {
                set<int>::iterator it;
                it = setP.lower_bound (val);
                setP.erase (setP.begin (), it);
                break;
            } else {
                setP.insert (val);
            }
            atual = val;
        }
        set<int>::iterator it;
        for (it = setP.begin (); it != setP.end (); it++) 
            printf ("%d ", (*it));
        printf ("\n");

        set<int> setQ;
        while (!seenQ[atual]) {
            seenQ[atual] = true;
            int val = 0;
            for (int i = 0; i <= numQ; i++) 
                val += (q[i] * pot[atual][numQ-i]) % r;
            if (seenQ[val]) {
                break;
            } else {
                if (setP.find (val) != setP.end ()) setQ.insert (val);
                else break;
            }
            atual = val;
        }
        printf ("x %d tamQ %d tamP %d\n", x, tamQ, tamP);
        int tamQ = setQ.size (), tamP = setP.size ();
        if (tamQ == tamP) {
            printf ("tamQ %d\n", tamQ);
            set<int>::iterator it;
            for (it = setQ.begin (); it != setQ.end (); it++) 
                printf ("%d ", (*it));
            printf ("\n");
            ans++;
        }
    }
    printf ("%d\n", ans);
}

