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
const int MAXN = 200004;

int main() {
    int n;
    scanf("%d", &n);
    multiset<pair<int, int> > min1, min2;
    vector<int> v[MAXN];
    if (n == 1) {
        printf("1\n1\n");
        return 0;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            int a;
            scanf("%d", &a);
            v[i].push_back(a);
        }
        sort(v[i].begin(), v[i].end());
        min1.insert(make_pair(v[i][0], i));
        if (min1.size() > 2) {
            min1.erase(min1.begin());
        }
        min2.insert(make_pair(v[i][1], i));
        if (min2.size() > 2) {
            min2.erase(min2.begin());
        }
    }
    vector<int> asdf;
    for(int i=0;i<n;i++) {
        set<pair<int, int> >::iterator it = min1.begin();
        it++;
        if (it->second == i) it--;
        set<pair<int, int> >::iterator it2 = min2.begin();
        it2++;
        if (it2->second == i) it2--;
        if (v[i][2] > it2->first && v[i][1] > it->first) asdf.push_back(i+1);
    }
    printf("%d\n", (int)asdf.size());
    for(int i=0;i<asdf.size();i++) {
        printf("%d ", asdf[i]);
    }
    printf("\n");
}

