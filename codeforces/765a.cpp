#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112;

int n, cn;
char t[5];
string h;

string get() {
    char s[20];
    scanf(" %s", s);
    return string(s);
}

int main() {
    scanf(" %d", &n);
    scanf(" %s", t);
    h = t;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        string a, b, l;
        l = get();
        a = l.substr(0, 3);
        b = l.substr(5, 3);
        if (a == h) cn++;
        if (b == h) cn--;
    }
    if (!cn) puts("home");
    else puts("contest");
}

