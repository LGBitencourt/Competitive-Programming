#include <cstdio>

int mdc(int a, int b) {
    int c;
    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n, n1, n2, d1, d2;
    char b, o;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, mdcc;
        scanf("%d %c %d %c %d %c %d", &n1, &b, &d1, &o, &n2, &b, &d2);
        switch(o) {
            case '+':
                a = (n1*d2 + n2*d1), b = (d1*d2);
                break;
            case '-':
                a = (n1*d2 - n2*d1), b = (d1*d2);
                break;
            case '*':
                a = n1*n2, b = d1*d2;
                break;
            case '/':
                a = n1*d2, b = n2*d1;
                break;
            default:
                break;
        }
        mdcc = mdc(a, b);
        if (mdcc < 0) {
            mdcc = -mdcc;
        }
        printf("%d/%d = %d/%d\n", a, b, a/mdcc, b/mdcc);
    }
    return 0;
}
