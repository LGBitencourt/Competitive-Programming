#include <cstdio>
#include <set>

using namespace std;

int main() {
    int n, id, s = 0;
    char op;
    set<int> room;
    scanf(" %d", &n);
    while (n--) {
        scanf(" %c %d", &op, &id);
        if (op == '+') room.insert(id);
        else {
            set<int>::iterator f = room.find(id);
            if (f != room.end())
                room.erase(f);
            else s++;
        }
        if (room.size() > s) s = room.size();
    }
    printf("%d\n", s);
}
