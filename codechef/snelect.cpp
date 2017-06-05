#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112;

char s[MAXN];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s", s);
        int m = 0, c = 0;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == 'm') {
                m++;
                if (i && s[i-1] == 's') c--;
                else if (s[i+1] != 0 && s[i+1] == 's') s[i+1] = 't';
            } else if (s[i] == 's') c++;
        }
        if (c == m) puts("tie");
        else printf("%s\n", c > m ? "snakes" : "mongooses");
    }
}

