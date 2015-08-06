#include <cstdio>
#include <set>

using namespace std;

int main() {
    set<int> p;
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf(" %d", &x);
        p.insert(x);
    }
    printf("%d\n", p.size());
}
