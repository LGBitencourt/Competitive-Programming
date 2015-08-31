#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, t, v, s = 0;
    priority_queue<int> q;
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        cin >> v;
        q.push(v);
    }
    while (t <= q.top()) {
        v = q.top();
        q.pop();
        q.push(v - 1);
        s++, t++;
    }
    cout << s << '\n';
}
