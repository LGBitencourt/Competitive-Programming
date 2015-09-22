#include <iostream>
#include <utility>
#include <algorithm>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ppi;

int main () {
    ios::sync_with_stdio(false);
    int n, d;
    long long int sum = 0, max = 0;
    ppi p[100005];
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int m, s;
        cin >> m >> s;
        p[i] = make_pair(m, s);
    }
    sort(p, p + n);
    int i = 0;
    for (int j = 0; j < n; j++) {
        sum += p[j].ss;
        while (p[j].ff - p[i].ff >= d) sum -= p[i].ss, i++;
        if (sum > max) max = sum;
    }
    cout << max << '\n';
}
