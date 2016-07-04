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
const int MAXN = 10004;
const int modn = 1000000007;


char s[MAXN];

int calc (char c) {
    if (c == 'K' || c == 'Q' || c == 'J' || c == 'T')
        return 10;
    if (c >= '2' && c <= '9')
        return c-'0';
}

int main() {
    while (scanf (" %s", s) && strcmp (s, "JOKER") != 0) {
        int player = 0, dealer = 0;
        bool Aappear = false;
        for (int i = 0; i < 4; i++) {
            if (i == 0 || i == 2) {
                if (s[i] == 'A') {
                    Aappear = true;
                    if (player < 11)
                        player += 11;
                    else 
                        player += 1;
                }               
                else { 
                    player += calc (s[i]);
                }
            } else {
                if (s[i] == 'A') {
                    if (dealer < 11)
                        dealer += 11;
                    else 
                        dealer += 1;
                }               
                else 
                    dealer += calc (s[i]);      
            }
        }
        int len = strlen (s), tmpD = dealer;
        bool win = false;
        for (int i = 4; tmpD < 17 && i < len; i++) {
            if (s[i] == 'A') {
                if (tmpD < 11)
                    tmpD += 11;
                else 
                    tmpD += 1;
            }               
            else 
                tmpD += calc (s[i]);
        }
        if (tmpD > 21)
            win = true;
        else if (21-player <= 21-tmpD)
            win = true;
        for (int i = 4; !win && i < len; i++) {
            if (s[i] == 'A') {
                Aappear = true;
                if (player < 11)
                    player += 11;
                else 
                    player += 1;
            }               
            else 
                player += calc (s[i]);
            if (player > 21) {
                if (Aappear) {
                    player -= 10;
                    Aappear = false;
                }
                else 
                    break;
            }
            tmpD = dealer;
            for (int j = i+1; tmpD < 17 && j < len; j++) {
                if (s[j] == 'A') {
                    if (tmpD < 11)
                        tmpD += 11;
                    else 
                        tmpD += 1;
                }               
                else 
                    tmpD += calc (s[j]);
            }
            if (tmpD > 21)
                win = true;
            else if (21-player <= 21-tmpD)
                win = true;
        }

        if (win)
            printf ("Yes\n");
        else 
            printf ("No\n");
    }
}

