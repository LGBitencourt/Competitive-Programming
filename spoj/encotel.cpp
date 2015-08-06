#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char getNumberByChar(char c) {
    if (c >= 'A' && c <= 'C') return '2';
    else if (c >= 'D' && c <= 'F') return '3';
    else if (c >= 'G' && c <= 'I') return '4';
    else if (c >= 'J' && c <= 'L') return '5';
    else if (c >= 'M' && c <= 'O') return '6';
    else if (c >= 'P' && c <= 'S') return '7';
    else if (c >= 'T' && c <= 'V') return '8';
    else if (c >= 'W' && c <= 'Z') return '9';
}

int main() {
    string s;
    while (getline(cin, s)) {
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == '1' || s[i] == '0' || s[i] == '-')
                putchar(s[i]);
            else printf("%c", getNumberByChar(s[i]));
        }
        putchar('\n');
    }
}
