#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main() {
    int p, s;
    while (cin >> p >> s, p != 0) {
        map<int, int> so;
        for (int i = 0; i < s; i++) {
            int init, end;
            cin >> init >> end;
            so.insert(make_pair(end, init));
        }
        for (map<int, int>::iterator it = so.begin(); it != so.end(); ++it) {
            start
        }
    }
}
