#include <cstdio>
#include <cmath>

double normPV(int x, int y, int a, int b) {
    return sqrt(pow(b*x-y*a, 2));
}

int main() {
    int n, xc, yc, r, x1, y1, x2, y2, f = 0;
    double d, eps;
    eps = 0.00001;
    scanf(" %d %d %d %d", &n, &xc, &yc, &r);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        d = normPV(xc-x1, yc-y1, xc-x2, yc-y2)/sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
        if (d <= r) {
            f++;
            if (d == r + eps) break;
        }
    }
    printf("%d\n", f);
}
