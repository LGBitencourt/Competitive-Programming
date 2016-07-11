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
const int MAXN = 1004;
const int modn = 1000000007;

map<char, char> m;
char in[MAXN];
char vowel[6] = {'a', 'i', 'y', 'e', 'o', 'u'};
char consoant[20] = {'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'};

char get_c(char c) {
    bool is_upper = isupper(c);
    c = tolower(c);
    int i;
    for (i = 0; i < 6; i++) if (c == vowel[i]) break;
    if (i < 6) {
        int index = (i + 3) % 6;
        return (is_upper) ? toupper(vowel[index]) : vowel[index];
    }
    for (i = 0; i < 20; i++) if (c == consoant[i]) break;
    int index = (i + 10) % 20;
    return (is_upper) ? toupper(consoant[index]) : consoant[index];
}

void pre() {
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        char C = 'A' + i;
        m[c] = get_c(c);
        m[C] = get_c(C);
    }
}

int main() {
    pre();
    while (gets(in) != NULL) {
        int len = strlen(in);
        for (int i = 0; i < len; i++) {
            if ((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z')) printf("%c", m[in[i]]);
            else printf("%c", in[i]);
        }
        printf("\n");
    }
}

