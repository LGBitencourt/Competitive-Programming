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
const int MAXN = 1004;

int n;
int q[5];
char s[MAXN];

int get_i(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
}

char get_c(int c) {
    if (c == 0) return 'A';
    if (c == 1) return 'C';
    if (c == 2) return 'G';
    if (c == 3) return 'T';
}

int main() {
    scanf(" %d", &n);
    scanf(" %s", s);
    if (n % 4) {
        printf("===\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') continue;
        int j = get_i(s[i]);
        q[j]++;
    }
    for (int i = 0; i < 4; i++)
        if (q[i] > (n / 4)) {
            printf("===\n");
            return 0;
        }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            for (int j = 0; j < 4; j++) {
                if (q[j] < (n / 4)) {
                    q[j]++;
                    printf("%c", get_c(j));
                    break;
                }
            }
        } else printf("%c", s[i]);
    }
    printf("\n");
}

