#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

ll r[6];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= 4; i++)
        for (int j = 1; j <= m; j++)
            if ((j + i) % 5 == 0) r[i]++;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += r[i%5];
    cout << sum << endl;
}
