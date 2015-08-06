#include <cstdio>

int main() {
    int s, e, t = 1;
    scanf("%d %d", &s, &e);
    
    s++;
    while ((s % 24) != e) s++, t++;

    printf("O JOGO DUROU %d HORA(S)\n", t);
}
