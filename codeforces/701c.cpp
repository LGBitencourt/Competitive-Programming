#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
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

int in[MAXN];
int app[60];

int get_i(char c) {
    if (isupper(c)) return c - 'A' + 27;
    return c - 'a';
}


int main() {
    int n, k = 0;
    scanf (" %d", &n);
    for( int i = 0; i < n; ++i ) {
        char y;
        scanf (" %c", &y);
        in[i] = get_i(y);
    }
    for( int i = 0; i < n; ++i ) {
        if(app[in[i]] == 0) k++;
        app[in[i]]++;
    }
    memset( app, 0, sizeof( app ));
    int begin = 0, end = -1;
    int best = -1;
    int ansbegin, ansend;
    int cnt = 0;
    while(1) {
        if(cnt < k) {
            end++;
            if(end == n)
                break;
            if(app[in[end]] == 0)
                cnt++;
            app[in[end]]++;
            continue;
        }
        while(app[in[begin]] > 1) {
            app[in[begin]]--;
            begin++;
        }
        if(best == -1 || end - begin < best) {
            best = end - begin;
            ansbegin = begin;
            ansend = end;
        }
        app[in[begin]]--;
        begin++;
        cnt--;
    }
    printf("%d\n", ansend - ansbegin + 1);
}
