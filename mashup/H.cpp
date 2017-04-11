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
const int MAXN = 10004;

char s1[200005];
char s2[200005];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    bool t = false;
    s1[n] = s2[n] = '0';
    n++;
    int c = 0;
    for(int i=0;i<n;i++) {
        if (s1[i] != s2[i]) t = true;
        else {
            if (t == true) c++;
            t = false;
        }
    }
    printf("%d\n", c);
}

