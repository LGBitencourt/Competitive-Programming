#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int n, b = 0, r = 0;
char v[MAXN];
char vr[MAXN], vb[MAXN];
bool needs = false;

int main() {
    scanf(" %d", &n);
    scanf(" %c", &v[0]);
    (v[0] == 'r') ? r++ : b++;
    for (int i = 1; i < n; i++) {
        scanf(" %c", &v[i]);
        if (v[i] == 'r') r++;
        else b++;
        if (v[i] == v[i-1]) needs = true;
    }
    if (!needs) printf("0\n");
    else if (b == 0 || r == 0)
        printf("%d\n", n/2);
    else {
        int sr = 0, sb = 0, mb = 0, mr = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) vr[i] = 'b', vb[i] = 'r';
            else vr[i] = 'r' , vb[i] = 'b';
        }
        for (int i = 0; i < n; i++) {
            if (vr[i] != v[i]) {
                if (v[i] == 'r') sb++;
                if (v[i] == 'b') sr++;
            }
        }
        mr = max(sr, sb);
        sr = sb = 0;
        for (int i = 0; i < n; i++) {
            if (vb[i] != v[i]) {
                if (v[i] == 'r') sb++;
                if (v[i] == 'b') sr++;
            }
        }
        mb = max(sr, sb);
        printf("%d\n", min(mr, mb));
    }
}

