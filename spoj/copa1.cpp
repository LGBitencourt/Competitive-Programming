#include <cstdio>
#include <queue>

using namespace std;

int main() {
    queue<char> teams;
    int g1, g2;
    char t1, t2;
    for (int i = 0; i < 16; i++) teams.push('A' + i);
    while (teams.size() > 1) {
        scanf(" %d %d", &g1, &g2);
        t1 = teams.front(), teams.pop();
        t2 = teams.front(), teams.pop();
        if (g1 > g2) teams.push(t1);
        else teams.push(t2);
    }
    printf("%c\n", teams.front());
}
