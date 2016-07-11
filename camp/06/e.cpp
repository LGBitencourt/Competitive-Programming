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

int rune[MAXN][MAXN], freq[MAXN][30];

int main() {
    int gates;
    scanf ("%d", &gates);
    while (gates--) {
        int numRings, numRunes;
        scanf ("%d %d", &numRings, &numRunes);
        int inval = 0;
        memset (freq, 0, sizeof freq);

        for (int i = 0; i < numRunes; i++) {
            int a;
            for (int j = 0; j < 3; j++) {
                scanf ("%d", &a);
                if (a == 0 || a == -0) 
                    inval |= (1 << 3);
                else if (a < -numRings || a > numRings)
                    inval |= (1 << 2);
                freq[i][abs (a)]++;
                rune[i][j] = a;
            }
            scanf ("%d", &a);
            for (int j = 1; j <= numRings; j++)
                if (freq[i][j] > 1) {
        //            printf ("j %d\n", j);
                    inval |= (1 << 1);
                    break;
                }
        }
        if ((inval & (1 << 3)) > 0) {
            printf ("INVALID: NULL RING\n");
        } else if ((inval & (1 << 2)) > 0) {
            printf ("INVALID: RING MISSING\n");
        } else if ((inval & (1 << 1)) > 0) {
            printf ("INVALID: RUNE CONTAINS A REPEATED RING\n");
        } else {
            bool ans = false;
            for (int mask = 0; !ans && mask < (1 << numRings); mask++) {
                bool appear;
                for (int i = 0; i < numRunes; i++) {
                    appear = false;
                    for (int j = 0; !appear && j < 3; j++) {
                        int pos = abs (rune[i][j]) - 1;
            //            printf ("rune %d mask %d\n", rune[i][j], mask);
                        if (rune[i][j] > 0) {
                            if ((mask & (1 << pos)) > 0) appear = true;
                        } else {
                            if ((mask & (1 << pos)) == 0) appear = true;
                        }
                    }
                    if (!appear) break; 
                }
                if (appear) ans = true;
            }
            
            if (ans) {
             //   printf ("mask %d\n", mask);
                printf ("RUNES SATISFIED!\n");
            } else printf ("RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n");
        }
    }
}

