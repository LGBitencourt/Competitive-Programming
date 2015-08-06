#include <cstdio>

void mdc(int a, int b, int *alpha, int *beta, int *mdc) {
    int x[2] = {1, 0};
    int y[2] = {0, 1};
 
    while (a % b != 0) {
        int quociente = a / b;
 
        int temp = a;
        a = b;
        b = temp % b;
 
        int X = x[0] - (x[1] * quociente);
        int Y = y[0] - (y[1] * quociente);
 
        x[0] = x[1];
        x[1] = X;
        y[0] = y[1];
        y[1] = Y;
    }
 
    *mdc = b;
    *alpha = x[1];
    *beta = y[1];
}

int main() {
    int m, n, a, b, x;
    mdc(5, 7, &a, &b, &x);
    printf("%d %d %d\n", a, b, x);

    while ((-x*a/n) -1 <= 3 && 3 < -x*a/n) x++;
    printf("%d\n", );
    
}
