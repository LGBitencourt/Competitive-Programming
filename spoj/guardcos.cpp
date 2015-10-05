#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    double d, vg, vf;
    while (scanf(" %lf %lf %lf", &d, &vf, &vg) != EOF) {
        double tf = 12 / vf;
        double tg = sqrt(144 + (d * d))/vg;
        if (tg <= tf) printf("S\n");
        else printf("N\n");
    }
}
