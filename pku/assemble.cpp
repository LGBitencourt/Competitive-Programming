#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

#define MAX 10000005
#define pii pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, n, b;
    string trash, type_s;
    cin >> t;
    while (t--) {
        int types = 0;
        map<string, int> type;
        vector<pii> components[1005];
        cin >> n >> b;
        for (int i = 0; i < n; i++) {
            int price, quality;
            cin >> type_s >> trash >> price >> quality;
            if (type.find(type_s) == type.end())
                type.insert(make_pair(type_s, types++));
            components[type[type_s]].push_back(make_pair(price, quality));
        }

        int lo = 0, hi = MAX, mid;
        while (lo != hi) {
            mid = (lo + hi + 1)/2;
            /*int i, j;
            for (i = 0; i < n; i++) {
                for (j = 0; j < components[i].size() && components[i][j].second <= mid; j++)
                if (j != components[i].size()) break;
            }
            if (i != n) hi = mid;
            else lo = mid;*/

        }
        cout << mid << '\n';
    }
}
