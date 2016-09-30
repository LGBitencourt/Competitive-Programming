#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, k;
int l[MAXN];
string pass[MAXN];
string p;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> pass[i];
        l[(int) pass[i].length()]++;
    }
    cin >> p;
    int sum = 0, acc = 0;
    for (int i = 0; i < (int) p.length(); i++)
        sum += l[i];
    int best = 0, worst = 0;
    for (int i = 0; i < sum; i++) {
        acc++, best++;
        if (acc == k) best += 5, acc = 0;
    }
    best++;
    worst = best - 1;
    for (int i = 0; i < l[(int) p.length()] - 1; i++) {
        acc++, worst++;
        if (acc == k) worst += 5, acc = 0;
    }
    worst++;
    cout << best << " " << worst << endl;
}
