#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    char dna[101];
    string mdna;
    set<string> s;
    while (scanf(" %d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf(" %s", dna);
            mdna = dna;
            sort(mdna.begin(), mdna.end());
            s.insert(mdna);
        }
        printf("%d\n", s.size());
        s.clear();
    }
}
