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

bool v[30];

int get_i(char c) {
    if (islower(c)) return c - 'a';
    return c - 'A';
}

int main() {
    int n;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf (" %c", &c);
        v[get_i(c)] = true;
    }
    bool is = true;
    for (int i = 0; i < 26; i++)
        if (!v[i]) is = false;
    printf("%s\n", is ? "YES" : "NO");
}

