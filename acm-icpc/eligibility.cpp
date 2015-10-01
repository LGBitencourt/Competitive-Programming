#include <cstdio>
#include <string>

using namespace std;

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        char name[30];
        int yg, mg, dg, yb, mb, db, courses;
        scanf (" %s %d/%d/%d %d/%d/%d %d", name, &yg, &mg, &dg, &yb, &mb, &db, &courses);
        if (yg >= 2010) {
            printf("%s eligible\n", name);
            continue;
        } else if (yb >= 1991) {
            printf("%s eligible\n", name);
            continue;
        } else if (courses < 41) {
            printf("%s coach petitions\n", name);
            continue;
        } else {
            printf("%s ineligible\n", name);
        }
    }
}
