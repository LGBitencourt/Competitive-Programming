#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fp first
#define fs second
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
const int MAXN = 200005;
const int modn = 1000000007;

int n, m;
int freq[MAXN], ans[MAXN];
map<pii, pii> v;

void clear () {
    v.clear ();
    for (int i = 1; i <= n; i++)
        freq[i] = ans[i] = 0;
}

int main() {
    freopen ("intouch.in", "r", stdin);
    freopen ("intouch.out", "w", stdout);
    while (scanf ("%d %d", &n, &m) != EOF) {
        clear ();
        int a, b;
        char c;
        for (int i = 0; i < m; i++) {
            scanf (" %c", &c);
            if (c == '!') {
                scanf ("%d", &a);
                freq[a]++;
            } else {
                scanf ("%d %d", &a, &b);
                if (a > b) swap (a, b);
                pii dupla = pii (a, b);
                if (c == '-') {
                    ans[a] += freq[b] - v[dupla].fs;
                    ans[b] += freq[a] - v[dupla].fp;     
                    v[dupla].fp = -1;
                    v[dupla].fs = -1;
                } else {
                    v[dupla].fp = freq[a];
                    v[dupla].fs = freq[b];
                }
            }
        }
        for (auto i : v) {
            int a = i.fp.fp, b = i.fp.fs;
            int freqA = i.fs.fp, freqB = i.fs.fs;
            if (freqA == -1)
                continue;
            ans[a] += freq[b] - freqB;
            ans[b] += freq[a] - freqA;
        }
        for (int i = 1; i <= n; i++) 
            printf ("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    fclose (stdout);
}

