#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

int prime[MAXN];
vector<int> p;

void sieve() {
    for (int i = 2; i < MAXN; i++)
        prime[i] = true;
    for (int i = 2; i < MAXN; i++) {
        if (!prime[i]) continue;
        p.pb(i);
        for (int j = i + i; j < MAXN; j += i)
            prime[j] = false;
    }
}

int main() {
    sieve();
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n;
        scanf(" %d", &n);
        int j = 0;
        for (int i = 30; j < n; i++) {
            int d = 0;
            for (int v : p) {
                if (i % v == 0) d++;
                if (d >= 3) break;
            }
            if (d >= 3) j++;
            if (j == n) printf("%d\n", i);
        }
    }
}

