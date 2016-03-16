#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 10004;
////////////////0123456789
const int MAX = 105;
const int modn = 1000000007;

int n;
bool t[inf];
int used[MAX];
pii dish[MAX];

bool cmp (pii a, pii b) {
    if (a.ss != b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

int main() {
    int l = 0, h = inf;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %d %d", &dish[i].ff, &dish[i].ss);
        if (dish[i].ss - dish[i].ff < h) h = dish[i].ss - dish[i].ff;
    }
    sort (dish, dish + n, cmp);
    while (l < h) {
        bool can = true;
        int mid = (l+h+1)/2;
        for (int i = 0; i < inf; i++)
            t[i] = false;
        memset (used, 0, sizeof used);
        for (int i = 0; i < n; i++) {
            for (int j = dish[i].ff; j < dish[i].ss; j++) {
                if (!t[j] && used[i] < mid) {
                    t[j] = true;
                    used[i]++;
                }
            }
        }
        for (int i = 0; i < n && can; i++)
            if (used[i] < mid) can = false;
        if (can) l = mid;
        else h = mid-1;
    }
    printf ("%d\n", n*l);
}

