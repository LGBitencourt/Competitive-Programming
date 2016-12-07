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
const int MAXN = 500004;

struct p {
    char t;
    int x, y;
    p(){}
    p(char c, int a, int b) { t = c, x = a, y = b; }
} nr[10], king;

int get_d(p i) {
    if (i.x == king.x) return i.y > king.y;
    if (i.y == king.y) return 2 + (i.x < king.x);
    if (i.x - i.y == king.x - king.y) return 4 + (i.x > king.x);
    if (i.x + i.y == king.x + king.y) return 6 + (i.x > king.x);
    return -1;
}

int dist(p i) {
    return max(abs(king.x - i.x), abs(king.y - i.y));
}

int main() {
    int n;
    bool check = false;
    scanf(" %d", &n);
    scanf(" %d %d", &king.y, &king.x);
    for (int i = 0; i < 8; i++)
        nr[i] = p('*', 0, 0);
    for (int i = 0; i < n; i++) {
        char c;
        int x, y, dir;
        scanf(" %c %d %d", &c, &y, &x);
        p j = p(c, x, y);
        dir = get_d(j);
        if (dir != -1 && (nr[dir].t == '*' || dist(j) < dist(nr[dir])))
            nr[dir] = j;
    }
    for (int i = 0; i < 8; i++) {
        if (i < 4 && nr[i].t == 'R') check = true;
        if (i >= 4 && nr[i].t == 'B') check = true;
        if (nr[i].t == 'Q') check = true;
    }
    puts(check ? "YES" : "NO");
}

