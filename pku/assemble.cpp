#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <climits>
#include <string>

#define MAX 1000000005
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
            components[type[type_s]].push_back(make_pair(quality, price));
        }

        int lo = 0, hi = MAX, mid;
        while (lo != hi) {
            mid = (lo + hi + 1)/2;
            bool cagou = false;
            int o = 0;
            for (int i = 0; i < types; i++) {
                int c = INT_MAX;
                for (int j = 0; j < components[i].size(); j++)
                    if (components[i][j].first >= mid && components[i][j].second < c)
                        c = components[i][j].second;
                if (c == INT_MAX) {
                    cagou = true;
                    break;
                } else {
                    o += c;
                }
            }
            if (!cagou) {
                if (o <= b)
                    lo = mid;
                else
                    hi = mid - 1;
            } else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}
