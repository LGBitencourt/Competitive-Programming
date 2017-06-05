#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 1000004;

char a[MAXN], s[MAXN];

int main() {
    scanf(" %s", s);
    int l = strlen(s);
    int la = 0;
    for (int i = 1; i < l - 1; i++) {
        if (s[i-1] != 'C' && s[i+1] != 'C' && s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1])
            s[i-1] = s[i] = s[i+1] = 'C';
    }
    for (int i = 0; i < l; i++) {
        if (s[i] == 'C') {
            a[la] = 'C';
            i += 2;
        } else if (s[i] == 'R') {
            a[la] = 'S';
        } else if (s[i] == 'B') {
            a[la] = 'K';
        } else if (s[i] == 'L') {
            a[la] = 'H';
        }
        la++;
    }
    a[la + 1] = 0;
    printf("%s\n", a);
}

