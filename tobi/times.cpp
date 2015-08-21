#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    vector<string> teams[10000];
    map<int, string> m;
    priority_queue<int> pq;

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        string name;
        int skill;
        cin >> name >> skill;
        m.insert(pair<int, string>(skill, name));
        pq.push(skill);
    }

    for (int i = 0; i < n; i++) {
        teams[i % t].push_back(m[pq.top()]);
        pq.pop();
    }

    for (int i = 0; i < t; i++) {
        sort(teams[i].begin(), teams[i].end());
        cout << "Time " << i + 1 << '\n';
        for (vector<string>::iterator it = teams[i].begin(); it != teams[i].end(); ++it)
            cout << *it << '\n';
        cout << '\n';
    }
}
