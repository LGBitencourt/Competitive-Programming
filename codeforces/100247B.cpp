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

char str[1000005];

int main() {
    int n;
    scanf("%d", &n);
    map<vector<int>, int> m;
    for(int i=0;i<n;i++) {
        map<int, int> s;
        vector<int> v;
        scanf("%s", str);
        int k = strlen(str);
        int c = 1;
        for(int j=0;j<k;j++) {
            if (s[str[j]] == 0) {
                s[str[j]] = c++;
            }
            v.push_back(s[str[j]]);
        }
        m[v]++;
    }
    long long ans = 0;
    for(map<vector<int>, int>::iterator it = m.begin(); it!=m.end(); it++) {
        ans += (((long long)it->second)*((long long)it->second-1ll))/2ll;
    }
    printf("%lld\n", ans);
}

