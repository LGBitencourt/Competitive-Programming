#include <cstdio>
#include <string.h>
#include <iostream>

#define MAX 75

using namespace std;

int getCode(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    else if (c == '_') return 0;
    else if (c == '.') return 27;
}

char getCharByCipher(int c) {
    if (c >= 1 && c <= 26) return c + 'a' - 1;
    else if (c == 0) return '_';
    else if (c == 27) return '.';
}

int mod28(int i) {
    return ((i >= 0) ? i % 28 : (i % 28) + 28);
}

int main() {
    char plaintext[MAX], ciphertext[MAX];
    int plaincode[MAX], ciphercode[MAX];
    int k;
    
    while (scanf("%d", &k), k != 0) {
        int l = 0;
        char x;
        cin >> ciphertext;
        int n = strlen(ciphertext);
        while (ciphertext[l] != '\0') {
            plaincode[(k * l) % n] = mod28(getCode(ciphertext[l]) + l);
            l++;
        }
        for (int i = 0; i < l; i++) {
            printf("%c", getCharByCipher(plaincode[i]));
        }
        printf("\n");
    }

}
