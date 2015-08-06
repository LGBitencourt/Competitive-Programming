#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int d[26];
    string l;
    int t, max;
    char c;
    scanf(" %d", &t);
    scanf("%c", &c);
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 26; j++) d[j] = 0;
        getline(cin, l);
        for (int x = 0; x < l.length(); x++) d[l[x] - 'a'] = d[l[x] - 'a'] + 1;
        max = -1;
        for (int j = 0; j < 26; j++)  if (d[j] > max) max = d[j], c = 'a' + j;
        printf("%d %c\n", max, c);
    }
}
