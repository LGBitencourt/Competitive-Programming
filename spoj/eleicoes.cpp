#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n, x;
    map<int, int> keys;
    map<int, int> values;
    map<int, int>::iterator it;
    map<int, int>::reverse_iterator ti;
    scanf(" %d", &n);
    while (n-- > 0) {
        scanf(" %d", &x);
        it = keys.find(x);
        if (it == keys.end()) {
            keys.insert(make_pair(x, 1));
            values.insert(make_pair(1, x));
        } else {
            it->second += 1;
            values.insert(make_pair(it->second, x));
        }
    }
    it = values.end(), it--;
    printf("%d\n", it->second);
}
