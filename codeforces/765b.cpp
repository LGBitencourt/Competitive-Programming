#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int n;
char s[MAXN];

int main() {
    int cur = 0;
    bool ans = true;
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] > 'a' + cur) ans = false;
        else if (s[i] == 'a' + cur) cur++;
    }
    printf("%s\n", ans ? "YES" : "NO");
}

