#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool alphabet[26];
char first_letters[26];
char letters[28][28];
string input[105];

int main() {
    ios::sync_with_stdio(false);
    string word;
    int n, f = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        input[i] = word;
        if (!alphabet['a' - word[0]]) {
            alphabet['a' - word[0]] = true;
            first_letters[f++] = word[0];
        }
    }

    for (int j = 1; j < 105; j++) {
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (j >= input[i].length()) continue;
            if (!alphabet[input[i][j] - 'a']) {
                alphabet[input[i][j] - 'a'] = true;
                letters[j][c++] = input[i][j];
                letters[j][0] = '+', letters[j][c] = '-';
            }
        }
    }

    for (int i = 26; i >= 0; i--) {
        if (letters[i][0] != '+') continue;
        for (int j = 1; j <= 27 && letters[i][j] != '-'; j++)
            cout << letters[i][j];
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            char x = (char) 'a' + i;
        }
    }

    for (int i = 0; i < f; i++)
        cout << first_letters[i];
    cout << '\n';

}
