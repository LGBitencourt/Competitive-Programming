#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 212345;

int n;
int s[MAXN];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", s + i);
    int i = 0, j = n - 1;
    while (i < j) {
        if (i % 2 == 0) swap(s[i], s[j]);
        i++, j--;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", s[i]);
    puts("");
}

